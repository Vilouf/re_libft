/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:42:57 by vielblin          #+#    #+#             */
/*   Updated: 2024/10/16 15:22:17 by vielblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_freetab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	is_separator(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static void	*alloc_words(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], c))
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && !is_separator(str[i], c))
				i++;
		}
	}
	return (malloc((count + 1) * sizeof(char *)));
}

static char	*copy_word(const char *str, int start, int end, char **result)
{
	char	*word;
	int		i;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (ft_freetab(result));
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		start;

	result = alloc_words(s, c);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_separator(s[i], c))
			i++;
		start = i;
		while (s[i] && !is_separator(s[i], c))
			i++;
		if (i > start)
			result[j++] = copy_word(s, start, i, result);
	}
	result[j] = 0;
	return (result);
}
