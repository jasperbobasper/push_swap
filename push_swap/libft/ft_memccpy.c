/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:44:43 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/25 10:34:01 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//copies up to n bytes from src to dest, stopping when c is found
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)dest = *(char *)src;
		if (*(unsigned char *)src == (unsigned char)c)
			return (dest + 1);
		dest++;
		src++;
		i++;
	}
	return (0);
}
