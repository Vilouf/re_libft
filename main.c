#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(int ac, char **av)
{
	printf("VRAI %d\n", atoi(av[ac - 1]));
	printf("FAUX %d\n", ft_atoi(av[ac - 1]));
}
