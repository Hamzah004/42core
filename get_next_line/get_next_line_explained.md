````markdown
# get_next_line — Super Detailed Notes

This is my implementation of `get_next_line`.  
The idea:  
- We use a **stash** (persistent storage across multiple calls).  
- We use a **buffer** (temporary storage for each `read()` call).  
- On each call to `get_next_line`, we:  
  1. Read from the file into the buffer.  
  2. Append buffer contents to the stash.  
  3. Extract the next line from the stash.  
  4. Update the stash so it only contains leftovers.  
  5. Return the extracted line.  

The cycle repeats until EOF.

---

## ft_strjoin_free

```c
static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	if (!s1)                  // case: first call, stash is NULL
		s1 = ft_strdup("");   // duplicate "" into malloc'ed memory
	if (!s1)                  // check allocation failure
		return (NULL);
	result = ft_strjoin(s1, s2); // create new string = s1 + s2
	free(s1);                    // free old stash memory
	return (result);             // return new stash
}
````

### Detailed Explanation

* `s1` is the **stash**.

  * On the very first call, stash is still `NULL`.
  * We make it `""` (empty string) so we can join safely.
* If `ft_strdup("")` fails, we return `NULL` (critical error).
* We join stash + buffer with `ft_strjoin`.
* Important:

  * The new joined string is allocated in a new memory block.
  * The old stash is freed to avoid leaks.
* After this function, the returned `result` is the **new stash** containing both old stash and buffer.

**Why this is important**: It lets us accumulate file data safely across multiple reads without leaking the old stash.

---

## get\_line

```c
static char	*get_line(char *stash)
{
	char	*line;
	size_t	i;

	if (!stash || !*stash)         // stash empty or points to "\0"
		return (NULL);             // nothing to return
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;                      // move forward until newline or end
	if (stash[i] == '\n')
		i++;                      // include newline in the line
	line = ft_substr(stash, 0, i); // copy substring [0..i]
	if (!line)                     // malloc failed
		return (NULL);
	return (line);                 // return extracted line
}
```

### Detailed Explanation

* Purpose: To **extract one complete line** from stash.

* Steps:

  1. If stash is empty or only contains `'\0'`, we return `NULL` (EOF).
  2. Count characters until newline or `'\0'`.
  3. If we stopped at `'\n'`, include it by incrementing `i`.

     * This is required by the project: the returned line must include `\n` if present.
  4. Use `ft_substr` to allocate a new string containing `[stash[0..i-1]]`.
  5. Return that new string as the line.

* Note: This function **does not modify the stash**. It only returns the line.

* Modifying stash happens later in `new_stash`.

---

## new\_stash

```c
static char	*new_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;                      // skip characters until newline or end
	if (stash[i] == '\n')
		i++;                      // skip past the newline itself
	new_stash = ft_substr(stash, i, ft_strlen(stash) - i);
	free(stash);                   // free old stash
	if (!new_stash || new_stash[0] == '\0')
	{
		free(new_stash);          // if empty or malloc failed
		return (NULL);            // reset stash to NULL
	}
	return (new_stash);            // leftover stash
}
```

### Detailed Explanation

* Purpose: To **update stash** by removing the line we just returned.

* Steps:

  1. Move index `i` until the newline or end.
  2. If newline exists, move one more step (so leftovers start after `\n`).
  3. Use `ft_substr` to copy everything from `[i..end]`.
  4. Free the old stash, because we don’t need the old memory anymore.
  5. If new stash is empty (`""`) or allocation failed, free it and return `NULL`.

* Effect: After calling this, stash only contains **the leftover part after the first line**.

---

## read\_file

```c
static char	*read_file(int fd, ssize_t bytes_read, char *stash, char *buffer)
{
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)              // read error
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';       // null-terminate buffer
		stash = ft_strjoin_free(stash, buffer);
		if (!stash)                  // allocation failure
		{
			free(buffer);
			return (NULL);
		}
	}
	return (stash);
}
```

### Detailed Explanation

* Purpose: To **fill the stash with file contents** until we hit a newline or EOF.

* Parameters:

  * `fd` = file descriptor.
  * `bytes_read` = result of `read()`.
  * `stash` = previous contents (persistent).
  * `buffer` = temporary space for reading.

* Loop logic:

  * Continue while `bytes_read > 0` (still reading) **and** stash does not contain `\n`.
  * Each iteration:

    1. Call `read(fd, buffer, BUFFER_SIZE)`.

       * `> 0` = bytes read.
       * `0` = EOF.
       * `< 0` = error.
    2. If error: free buffer and return `NULL`.
    3. Add `'\0'` at the end of buffer to make it a proper C-string.
    4. Append buffer to stash with `ft_strjoin_free`.
    5. If that failed: free buffer and return `NULL`.

* Important:

  * `buffer` is **not freed here** on success — it will be freed in `get_next_line`.
  * On error, it’s freed here to prevent leaks.

---

## get\_next\_line

```c
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)                       // malloc failed
		return (NULL);
	bytes_read = 1;                        // set >0 to enter loop
	stash = read_file(fd, bytes_read, stash, buffer);
	free(buffer);                      // buffer no longer needed
	line = get_line(stash);            // extract one line from stash
	stash = new_stash(stash);          // update stash with leftovers
	return (line);                     // return extracted line
}
```

### Detailed Explanation

* Purpose: This is the **public function** used by the user.

* Flow:

  1. Validate inputs:

     * Invalid fd or bad `BUFFER_SIZE` → return `NULL`.
  2. Allocate buffer of size `BUFFER_SIZE + 1` (extra 1 for `'\0'`).

     * If allocation fails → return `NULL`.
  3. Set `bytes_read = 1` just so the loop in `read_file` starts.
  4. Call `read_file`: this fills stash with enough data until newline or EOF.
  5. Free buffer (we don’t need it anymore after reading).
  6. Extract a line from stash with `get_line`.
  7. Update stash with leftovers using `new_stash`.
  8. Return the line.

* Key detail:

  * `stash` is declared `static`, meaning it persists between multiple calls to `get_next_line`.
  * That’s how we can keep leftovers across calls.

---
