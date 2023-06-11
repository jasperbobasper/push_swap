/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:02:07 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/21 15:57:39 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Returns new string concatenating s1 and s2 (uses malloc).
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;
	int		x;
	int		y;

	x = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (s1[x] != 0)
	{
		str[x] = s1[x];
		x++;
	}
	y = 0;
	while (s2[y] != 0)
	{
		str[x] = s2[y];
		x++;
		y++;
	}
	str[x] = 0;
	return (str);
}
