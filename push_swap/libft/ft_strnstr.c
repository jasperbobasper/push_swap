/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:32:31 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/25 15:22:43 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//returns pointer to first occurence of sstr in the first n bytes of str.
char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	size_t	i;
	size_t	ii;

	if (substr[0] == 0)
		return ((char *)str);
	i = 0;
	while (i < n && str[i])
	{
		ii = 0;
		while (str[i + ii] == substr[ii] && (i + ii) < n && str[i + ii])
		{
			ii++;
			if (substr[ii] == 0)
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
