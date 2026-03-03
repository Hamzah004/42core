#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static char	*stash = NULL;

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!str1 || !str2)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
	{
		new_str[j] = str1[i];
		i++;
		j++;
	}
	i = 0;
	while (str2[i])
	{
		new_str[j] = str2[i];
		j++;
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

static char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*new_str;
	size_t	s_size;

	s_size = ft_strlen(str) + 1;
	new_str = (char *)malloc(sizeof(char) * s_size);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < s_size - 1)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

int	ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

static char	*read_file(int fd, char *stash, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && (!stash || !ft_strchr(stash, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_free(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

static char	*get_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*new_stash(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*new_stash_ptr;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	len = ft_strlen(stash) - i;
	new_stash_ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_stash_ptr)
		return (NULL);
	j = 0;
	while (j < len)
	{
		new_stash_ptr[j] = stash[i + j];
		j++;
	}
	new_stash_ptr[j] = '\0';
	free(stash);
	if (new_stash_ptr[0] == '\0')
	{
		free(new_stash_ptr);
		return (NULL);
	}
	return (new_stash_ptr);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	stash = read_file(fd, stash, buffer);
	if (!stash)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	line = get_line(stash);
	stash = new_stash(stash);
	return (line);
}
