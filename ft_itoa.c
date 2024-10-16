/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:37:27 by vielblin          #+#    #+#             */
/*   Updated: 2024/10/16 15:20:10 by vielblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_lenght(long nbr)
{
	int	i;

	i = 1;
	while (nbr >= 10)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

static int	is_negative(long *n, int *len)
{
	if (*n < 0)
	{
		*n *= -1;
		*len = 1;
		return (-1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		len;
	int		sign;
	long	nbr;

	nbr = (long) n;
	len = 0;
	sign = is_negative(&nbr, &len);
	len += nbr_lenght(nbr);
	i = len;
	ret = (char *) malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[i] = 0;
	while (--i + sign >= 0)
	{
		ret[i] = nbr % 10 + 48;
		nbr /= 10;
	}
	if (sign == -1)
		ret[i] = '-';
	return (ret);
}
