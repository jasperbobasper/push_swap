/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:41:09 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/25 10:33:41 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//allocates and sets memory to 0's, returns pointer to allocated memory
void	*ft_calloc(size_t n, size_t size)
{
	size_t	i;
	size_t	sz;
	char	*str;

	i = 0;
	sz = n * size;
	str = malloc(sz);
	if (!str)
		return (NULL);
	while (i < sz)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
