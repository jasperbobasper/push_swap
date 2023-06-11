/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:52:32 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/25 10:34:44 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//copies n characters from src to dst, avoiding overlapping memory blocks
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	y;
	char	*dst_ptr;
	char	*src_ptr;

	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	y = 0;
	if (dst_ptr > src_ptr)
	{
		while (n > 0)
		{
			dst_ptr[n - 1] = src_ptr[n - 1];
			n--;
		}
	}
	else
	{
		while (y < n)
		{
			dst_ptr[y] = src_ptr[y];
			y++;
		}
	}
	return (dst);
}
