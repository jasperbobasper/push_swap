/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:42:38 by jpfannku          #+#    #+#             */
/*   Updated: 2021/05/31 17:24:11 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//copies c to the first n bytes of str
void	*ft_memset(void *str, int c, size_t n)
{
	size_t	y;
	size_t	z;

	y = 0;
	z = 0;
	while (y < n)
	{
		((char *)str)[z] = c;
		y++;
		z++;
	}
	return (str);
}
