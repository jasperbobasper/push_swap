/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:31:03 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/25 10:34:06 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//returns pointer to first instance of c in the first n bytes of str 
void	*ft_memchr(void *str, int c, size_t n)
{
	size_t	y;

	y = 0;
	if (!str)
		return (NULL);
	while (y < n && str)
	{
		if (*(unsigned char *)str == (unsigned char)c)
			return (str);
		y++;
		str++;
	}
	return (0);
}
