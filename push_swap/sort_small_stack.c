/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:20:48 by jpfannku          #+#    #+#             */
/*   Updated: 2021/12/31 11:03:52 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	two_num(t_stack *stack)
{
	if (stack->top->num > stack->bottom->num)
		sa_sb(stack, 'a');
	return (0);
}

int	three_num(int sz, t_stack *stack, char c)
{
	t_list	*tmp;

	if (sz == 2)
		return (two_num(stack));
	tmp = stack->top->prev;
	while (!(tmp->next->num < tmp->num) || !(tmp->num < tmp->prev->num))
	{
		if (tmp->next->num > tmp->prev->num && tmp->num < tmp->prev->num)
			ra_rb(stack, c);
		else if (tmp->next->num > tmp->prev->num && tmp->num > tmp->next->num)
			rra_rrb(stack, c);
		else
			sa_sb(stack, c);
		tmp = stack->top->prev;
	}
	return (0);
}

int	five_num(int sz, t_stack *sta, t_stack *stb)
{
	if (sz == 4)
		return (four_num(sta, stb));
	smallest_top(sta, 'a');
	pb(sta, stb);
	smallest_top(sta, 'a');
	pb(sta, stb);
	three_num(5, sta, 'a');
	pa(sta, stb);
	pa(sta, stb);
	return (0);
}

int	four_num(t_stack *sta, t_stack *stb)
{
	smallest_top(sta, 'a');
	pb(sta, stb);
	three_num(4, sta, 'a');
	pa(sta, stb);
	return (0);
}
