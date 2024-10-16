/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:20:56 by vielblin          #+#    #+#             */
/*   Updated: 2024/10/16 17:09:39 by vielblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_size;
	size_t	s2_size;
	char	*ret;

	i = 0;
	j = 0;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	ret = malloc((s1_size + s2_size + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < s1_size)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < s1_size + s2_size)
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	return (ret);
}
