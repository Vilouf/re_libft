/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:49:41 by vielblin          #+#    #+#             */
/*   Updated: 2024/10/15 13:59:20 by vielblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t	i;
	
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	i = 0;
	ret = malloc(nmemb * size);
	ft_bzero(ret, nmemb);
	return (ret);
}
