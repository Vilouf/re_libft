/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:29:20 by vielblin          #+#    #+#             */
/*   Updated: 2024/10/20 04:04:38 by vielblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	d = (char *)dest;
	s = (const char *)src;
	if ((char *)d > s)
	{
		while (n-- > 0)
			((char *)d)[n] = ((const char *)s)[n];
	}
	else
	{
		while (i < n)
		{
			((char *)d)[i] = ((const char *)s)[i];
			i++;
		}
	}
	return (dest);
}
