/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:17:32 by vielblin          #+#    #+#             */
/*   Updated: 2024/10/19 19:48:45 by vielblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*ret;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (start > s_len)
		len = 0;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < len && start < s_len)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = 0;
	return (ret);
}
