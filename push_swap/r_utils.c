/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:51:08 by jpfannku          #+#    #+#             */
/*   Updated: 2021/10/26 12:59:15 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra_rb(t_stack *stack, char c)
{
	int	temp;

	temp = stack_peek_top(stack);
	if (stack_pop_top(stack) < 0)
		return (-1);
	stack_push_bottom(stack, temp, 0, 0);
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rb\n", 1);
	return (0);
}

int	rr(t_stack *stacka, t_stack *stackb)
{
	if (ra_rb(stacka, ' ') < 0)
		return (-1);
	if (ra_rb(stackb, ' ') < 0)
		return (-1);
	ft_putstr_fd("rr\n", 1);
	return (0);
}

int	rra_rrb(t_stack *stack, char c)
{
	int	temp;

	temp = stack_peek_bottom(stack);
	if (stack_pop_bottom(stack) < 0)
		return (-1);
	stack_push_top(stack, temp, 0, 0);
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
	return (0);
}

int	rrr(t_stack *stacka, t_stack *stackb)
{
	if (rra_rrb(stacka, ' ') < 0)
		return (-1);
	if (rra_rrb(stackb, ' ') < 0)
		return (-1);
	ft_putstr_fd("rrr\n", 1);
	return (0);
}
