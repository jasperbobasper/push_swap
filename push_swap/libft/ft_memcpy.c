/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:39:13 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/25 10:34:33 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//copies n characters from src to dest
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	y;
	char	*dest_ptr;
	char	*src_ptr;

	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	y = 0;
	if (!n)
		return (dest);
	while (y < n)
	{
		dest_ptr[y] = src_ptr[y];
		y++;
	}
	return (dest);
}
