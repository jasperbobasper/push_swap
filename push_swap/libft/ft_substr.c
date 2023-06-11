/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:44:01 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/21 16:03:45 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Allocates and returns substring from the string 's' (with malloc)
//Substring begins at the index of 'start' and is max size 'n' 
char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	char	*str;
	size_t	i;
	size_t	sz;

	i = start;
	sz = 0;
	if (!s || start >= ft_strlen(s) || !n)
		return (ft_strdup(""));
	while (s[i] != 0 && sz < n)
	{
		sz++;
		i++;
	}
	str = (char *)malloc(sz * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[start] != 0 && i < n)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}
