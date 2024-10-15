/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vielblin <vielblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:41:25 by vielblin          #+#    #+#             */
/*   Updated: 2024/10/15 13:46:41 by vielblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	return (c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v'
		|| c == ' ');
}

static int	ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_is_negative(const char *str, int *start)
{
	int	negative;

	negative = 1;
	if (str[*start] && (str[*start] == '-' || str[*start] == '+'))
	{
		if (str[*start] == '-')
			negative = -1;
		*start += 1;
	}
	return (negative);
}

int	ft_atoi(const char *nptr)
{
	int	start;
	int	end;
	int	ret;
	int	mult;
	int	negative;

	start = 0;
	ret = 0;
	mult = 1;
	while (nptr[start] && ft_is_space(nptr[start]))
		start++;
	negative = ft_is_negative(nptr, &start);
	end = start;
	while (nptr[end] && ft_is_number(nptr[end]))
		end++;
	while (end-- > start)
	{
		ret += (nptr[end] - 48) * mult;
		mult *= 10;
	}
	ret *= negative;
	return (ret);
}