/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:14:32 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/01 19:17:19 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Copies up to size - 1 characters from src to dst, NULL-terminating the result.
size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	y;
	size_t	z;

	z = ft_strlen(src);
	y = 0;
	if (n != 0)
	{
		while (src[y] != 0 && y < n - 1)
		{
			dest[y] = src[y];
			y++;
		}
		dest[y] = '\0';
	}
	return (z);
}
