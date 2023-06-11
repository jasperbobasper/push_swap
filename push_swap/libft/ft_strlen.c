/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:12:28 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/25 10:35:37 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Takes a string as an argument and returns 
//its length (not including NULL terminator)
size_t	ft_strlen(const char *src)
{
	size_t	y;

	y = 0;
	while (src[y] != 0)
	{
		y++;
	}
	return (y);
}
