/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:06:13 by vielblin          #+#    #+#             */
/*   Updated: 2024/10/19 20:45:50 by vielblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_size;

	if (!dest && size == 0)
		return (ft_strlen(src));
	dest_size = ft_strlen(dest);
	if (size <= dest_size || src < 0)
		return (ft_strlen(src) + size);
	j = 0;
	i = dest_size;
	while (j < size - dest_size - 1 && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (dest_size + ft_strlen(src));
}
