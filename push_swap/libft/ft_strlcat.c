/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:38:50 by jpfannku          #+#    #+#             */
/*   Updated: 2021/12/30 13:53:33 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Appends src to the end of dst up to n - 1 bytes, NULL-terminating the result.
size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	slen;
	size_t	dlen;
	size_t	counter;
	size_t	offset;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	offset = dlen;
	counter = 0;
	while (src[counter] != 0 && offset < n - 1 && n != 0)
	{
		dest[offset] = src[counter];
		counter++;
		offset++;
	}
	if (n != 0)
		dest[offset] = '\0';
	if (dlen > n)
		return (n + slen);
	else
		return (dlen + slen);
}
