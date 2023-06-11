/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:52:56 by jpfannku          #+#    #+#             */
/*   Updated: 2021/06/25 10:35:37 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Applies function f to each character in s to create a new string (with malloc)
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*output;
	char	*str_ptr;
	int		i;

	output = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	str_ptr = (char *)s;
	i = 0;
	if (!output)
		return (0);
	while (str_ptr[i] != '\0')
	{
		output[i] = f(i, str_ptr[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
