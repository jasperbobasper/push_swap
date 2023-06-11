/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:42:16 by jpfannku          #+#    #+#             */
/*   Updated: 2021/12/30 13:52:50 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Returns a string representing the integer 
//received as an argument (uses malloc).
static	int	numbers(int sz, int n, char *str)
{
	int	pnum;
	int	y;

	y = sz - 1;
	str[y] = '\0';
	y--;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n >= 10)
	{
		pnum = n % 10;
		str[y] = '0' + pnum;
		n = n / 10;
		y--;
	}
	if (n < 10)
	{
		str[y] = '0' + n;
		y--;
	}
	return (0);
}

static	int	ncount(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = n * -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	if (n < 10)
		count++;
	return (count);
}

char	*ft_itoa(int n)
{
	int		sz;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sz = ncount(n) + 1;
	str = (char *)malloc(sizeof(char) * sz);
	if (!str)
		return (NULL);
	numbers(sz, n, str);
	return (str);
}
