/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:52:47 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/15 11:49:30 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//returns pointer to newly allocated duplicate of str (uses malloc)
char	*ft_strdup(const char *str)
{
	char	*s;
	int		x;
	size_t	len;

	len = ft_strlen(str);
	s = (char *)malloc(len * sizeof(char) + 1);
	x = 0;
	if (!s || !str)
		return (NULL);
	while (str[x] != 0)
	{
		s[x] = str[x];
		x++;
	}
	s[x] = 0;
	return (s);
}
