/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:42:57 by vielblin          #+#    #+#             */
/*   Updated: 2024/10/20 22:52:49 by vielblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freetab(char **tab)
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

static void	*alloc_words(const char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (malloc((count + 1) * sizeof(char *)));
}

static char	*copy_word(const char *str, size_t start, size_t end)
{
	char		*word;
	size_t		i;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
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

static size_t	prepare_word(const char *s, size_t *i, char c)
{
	size_t	start;

	while (s[*i] && s[*i] == c)
		*i += 1;
	start = *i;
	while (s[*i] && s[*i] != c)
		*i += 1;
	return (start);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		i;
	size_t		j;
	size_t		start;

	if (!s)
		return (NULL);
	result = alloc_words(s, c);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		start = prepare_word(s, &i, c);
		if (i > start)
		{
			result[j] = copy_word(s, start, i);
			if (!result[j])
				return (ft_freetab(result));
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}
