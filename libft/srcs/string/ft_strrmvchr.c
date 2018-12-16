void	ft_strrmvchr(char *s)
{
	if (s && *s)
	{
		s++;
		while (*s)
		{
			*(s - 1) = *s;
			s++;
		}
		*(s - 1) = 0;
	}
}
