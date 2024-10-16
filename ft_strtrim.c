/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:16:23 by vielblin          #+#    #+#             */
/*   Updated: 2024/10/15 16:39:57 by vielblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_trim(int c, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*ret;

	start = 0;
	i = 0;
	while (s1[start] && to_trim(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	if (start >= end)
		return (NULL);
	while (end >= 0 && to_trim(s1[end], set))
		end--;
	ret = malloc((end - start + 1) * sizeof(char));
	while (start <= end)
	{
		ret[i] = s1[start];
		i++;
		start++;
	}
	return (ret);
}
