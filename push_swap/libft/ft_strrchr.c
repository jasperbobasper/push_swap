/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:53:08 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/20 13:03:28 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//returns pointer to last occurence of c in str
char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	while (i != 0 && str[i] != c)
		i--;
	if (str[i] == c)
	{
		str = str + i;
		return ((char *)str);
	}
	else
		return (NULL);
}
