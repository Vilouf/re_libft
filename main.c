#include <stdio.h>
#include <string.h>
#include "libft.h"

// static void	ft_free(char **tab)
// {
// 	size_t	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// }

int	main(void)
{
	char	*test;
	int		i;

	scanf("%d", &i);
	test = ft_itoa(i);
	printf("Result: %s\n", test);
	free(test);
}
