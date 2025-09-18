/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:33:12 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/13 19:35:31 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *ft_strjoin_free(char *s1, char *s2)
{
  char  *result;

  if (!result)
    s1 = ft_strdup("");
  if (!s1)
    return (NULL);
  result = ft_strjoin(s1, s2);
  free(s1);
  return (s1);
}
static int ft_check(const char *s, int c) {
  int i;

  i = 0;
  while (s[i] != '\0') {
    if (s[i] == (unsigned char)c)
      return (1);
    i++;
  }
  return (0);
}

static char *get_line(char *stash) {
  size_t i;
  char *line;

  i = 0;
  while (stash[i] != '\n' && stash[i] != '\0')
    i++;
  if (stash[i] == '\n')
    i++;
  line = ft_substr(stash, 0, i);
  if (!line)
    return (NULL);
  return (line);
}

char *read_file(ssize_t offset, char *buffer, char *stash, int fd) {

  return (get_line(stash));
}

static char *new_stash(char *stash) {
  size_t i;
  char *old_stash;

  i = 0;
  while (stash[i] != '\n' && stash[i] != '\0')
    i++;
  if (stash[i] == '\n')
    i++;
  old_stash = stash;
  stash = ft_substr(stash, i, ft_strlen(stash) - i + 1);
  if (!stash)
    return (NULL);
  free(old_stash);
  return (stash);
}

char *get_next_line(int fd) {

  char *buffer = NULL;
  static char *stash;
  char *line;
  ssize_t offset;

  if (fd == -1 || BUFFER_SIZE <= 0)
    return (NULL);
  buffer = malloc(BUFFER_SIZE + 1);
  if (!buffer)
    return (NULL);
  offset = 1;
  while (offset > 0 && !ft_check(stash, '\n')) {

    offset = read(fd, buffer, BUFFER_SIZE);
    if (offset < 0)
      return (free(stash), free(buffer), buffer = NULL, NULL);
    buffer[offset] = '\0';
    stash = ft_strjoin_free(stash, buffer);
    if (!stash)
      return (free(stash), NULL);
  }
  free(buffer);
  line = get_line(stash);
  stash = new_stash(stash);
  return (line);
}
