/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_multiples.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:07:56 by jpfannku          #+#    #+#             */
/*   Updated: 2021/12/29 18:08:27 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_multiple(t_stack *stack, int num, char c)
{
	int	i;

	i = 0;
	if (num == 0)
		return (0);
	while (i < num)
	{
		if (ra_rb(stack, c) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	rr_multiple(t_stack *stack, int num, char c)
{
	int	i;

	i = 0;
	if (num == 0)
		return (0);
	while (i < num)
	{
		if (rra_rrb(stack, c) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	rrr_multiple(t_stack *stacka, t_stack *stackb, int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (0);
	while (i < num)
	{
		if (rr(stacka, stackb) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	rrrr_multiple(t_stack *stacka, t_stack *stackb, int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (0);
	while (i < num)
	{
		if (rrr(stacka, stackb) == -1)
			return (-1);
		i++;
	}
	return (0);
}
