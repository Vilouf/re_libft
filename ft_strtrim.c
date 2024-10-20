/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:16:23 by vielblin          #+#    #+#             */
/*   Updated: 2024/10/19 23:38:17 by vielblin         ###   ########.fr       */
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

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	i = 0;
	while (s1[start] && to_trim(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= 0 && to_trim(s1[end], set))
		end--;
	if (end < start)
		return (NULL);
	ret = ft_substr(s1, start, end - start + 1);
	if (!ret)
		return (NULL);
	return (ret);
}
