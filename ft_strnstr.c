/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:34:36 by vielblin          #+#    #+#             */
/*   Updated: 2024/10/15 13:39:45 by vielblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[0])
		return (big);
	while (big[i])
	{
		j = 0;
		while ((big[i + j] == little[j]) && little[j] && j < len)
			j++;
		if (little[j] == 0)
			return (&big[i]);
		i++;
	}
	return (0);
}
