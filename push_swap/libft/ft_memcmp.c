/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:32:44 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/25 10:34:22 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//compares the first n bytes of memory in str1 and str2
//return: 0 if same, > 0 if str1 bigger, < 0 if str1 smaller
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			a;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)str1;
	ptr2 = (unsigned char *)str2;
	a = 0;
	if (n == 0)
		return (0);
	while (a < n)
	{
		if (ptr1[a] != ptr2[a])
			return (ptr1[a] - ptr2[a]);
		a++;
	}
	return (0);
}
