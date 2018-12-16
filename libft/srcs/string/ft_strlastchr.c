char	*ft_strlastchr(char *s)
{
	if (s)
	{
		if (*s)
		{
			while (*s)
				s++;
			return (s - 1);
		}
		return (s);
	}
	return (0);
}
