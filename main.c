#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	test[] = "0123456789";
	char	test1[] = "abcdef";
	printf("%zu\n", strlcpy(test, test1, 5));
	// memmove(test, "ABCDEF", 4);
	// printf("VRAI %s\n", test);
	// char	test1[] = "0123456789";
	// ft_memmove(test1, "ABCDEF", 4);
	// printf("FAUX %s\n", test1);
}
