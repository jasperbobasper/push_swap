/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:52:40 by jpfannku          #+#    #+#             */
/*   Updated: 2021/12/30 13:53:27 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
//Allocates and returns an array of strings by splitting s
//with c as a delimiter. The array ends in a NULL pointer.
static size_t	word_count(char const *s, char c)
{
	size_t	wcount;
	size_t	i;

	wcount = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			wcount++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (wcount);
}

static int	next_word(char const *s, char c, int i)
{
	while (s[i] != 0)
	{
		i++;
		while (s[i] == c)
			return (i);
	}
	return (i);
}

static void	ft_free(char **ar, int i)
{
	while (i >= 0)
	{
		free(ar[i]);
		i --;
	}
	free(ar);
}

static char	**make_array(char const *s, char c, char **ar)
{
	size_t	i;
	size_t	ii;
	size_t	end;
	size_t	sz;

	i = 0;
	ii = 0;
	end = 1;
	while (i < word_count(s, c))
	{
		while (s[ii] == c)
			ii++;
		end = next_word(s, c, ii);
		sz = end - ii;
		ar[i] = ft_substr(s, ii, sz);
		if (!ar[i])
		{
			ft_free(ar, i);
			return (NULL);
		}
		ii = end + 1;
		i++;
	}
	ar[i] = 0;
	return (ar);
}

char	**ft_split(char const *s, char c)
{
	char	**end_array;
	size_t	sz;

	if (!s)
		return (NULL);
	sz = word_count(s, c);
	end_array = (char **)malloc(sz * sizeof (char *) + 1);
	if (!end_array)
		return (NULL);
	end_array = make_array(s, c, end_array);
	if (!end_array)
		return (NULL);
	return (end_array);
}
