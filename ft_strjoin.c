/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:20:56 by vielblin          #+#    #+#             */
/*   Updated: 2024/10/19 20:03:29 by vielblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnull(char const *s1, char const *s2)
{
	if (!s1)
	{
		if (s2)
			return (ft_strdup(s2));
	}
	else if (!s2)
	{
		if (s1)
			return (ft_strdup(s1));
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s1 || !s2)
		return (ft_strnull(s1, s2));
	i = 0;
	j = 0;
	ret = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = 0;
	return (ret);
}
