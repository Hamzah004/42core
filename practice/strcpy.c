int	strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}


char	*strcpy(char *dest, char *src)
{
	int	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
		return (dest);
}
