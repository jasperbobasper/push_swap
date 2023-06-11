/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:22:14 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/09 17:11:27 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//compares the first n bytes of str1 and str2, or until 0 is reached
//return: 0 if same, > 0 if str1 bigger, < 0 if str1 smaller
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	x;
	size_t	y;

	x = ft_strlen(str1);
	y = ft_strlen(str2);
	if (x < n)
		n = x + 1;
	if (y < n)
		n = y + 1;
	return (ft_memcmp(str1, str2, n));
}
