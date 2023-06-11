/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:49:30 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/25 14:49:54 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Allocates and returns a copy of s1 with set characters
//removed from beginning and end
static	size_t	check_letter(char ch, char const *set)
{
	int		y;
	size_t	mark;

	y = 0;
	mark = 0;
	while (set[y] != 0)
	{
		if (ch == set[y])
		{
			mark = 1;
			break ;
		}
		y++;
	}
	return (mark);
}

static	size_t	get_start(char const *s1, char const *set)
{
	size_t		x;

	x = 0;
	while (s1[x] != 0)
	{
		if (!check_letter(s1[x], set))
			break ;
		x++;
	}
	return (x);
}

static	size_t	get_end(char const *s1, char const *set)
{
	size_t		x;

	x = 0;
	if (ft_strlen(s1) > 0)
		x = ft_strlen(s1) - 1;
	while (x != 0)
	{
		if (!check_letter(s1[x], set))
			break ;
		x--;
	}
	return (x + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*tr;
	size_t		st;
	size_t		en;
	size_t		sz;

	st = get_start(s1, set);
	en = get_end(s1, set);
	sz = en - st;
	if (st >= en || en == 0 || en == 0)
		return (ft_calloc(1, 1));
	tr = (char *)malloc(sizeof(char) * (sz) + 1);
	if (!tr)
		return (0);
	sz = 0;
	while (st < en)
	{
		tr[sz] = s1[st];
		sz++;
		st++;
	}
	tr[sz] = '\0';
	return (tr);
}
