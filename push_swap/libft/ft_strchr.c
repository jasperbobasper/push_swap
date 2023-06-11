/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:52:43 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/25 10:35:00 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//returns pointer to first occurence of c in str
char	*ft_strchr(char *str, int c)
{
	int	x;

	x = 0;
	while (str[x] != 0 && str[x] != c)
	{
		x++;
	}
	if (str[x] == c)
		return (&str[x]);
	else
		return (0);
}
