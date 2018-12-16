#include "libft.h"

char	**ft_strtab_new(int len)
{
	char	**new;

	if (!(new = (char**)ft_memalloc(sizeof(*new) * (len + 1))))
		return (0);
	return (new);
}
