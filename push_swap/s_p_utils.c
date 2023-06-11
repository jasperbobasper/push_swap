/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_p_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:05:38 by jpfannku          #+#    #+#             */
/*   Updated: 2021/12/29 18:05:45 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa_sb(t_stack *stack, char c)
{
	int	temp;
	int	temp2;

	if (stack->top == NULL || stack->top->prev == NULL)
		return (-1);
	temp = stack_peek_top(stack);
	stack_pop_top(stack);
	temp2 = stack_peek_top(stack);
	stack_pop_top(stack);
	stack_push_top(stack, temp, 0, 0);
	stack_push_top(stack, temp2, 0, 0);
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	if (c == 'b')
		ft_putstr_fd("sb\n", 1);
	return (0);
}

int	ss(t_stack *stacka, t_stack *stackb)
{
	if (sa_sb(stacka, ' ') < 0)
		return (-1);
	if (sa_sb(stackb, ' ') < 0)
		return (-1);
	ft_putstr_fd("ss\n", 1);
	return (0);
}

int	pa(t_stack *stacka, t_stack *stackb)
{
	int	temp;

	temp = stack_peek_top(stackb);
	if (stack_pop_top(stackb) < 0)
		return (-1);
	stack_push_top(stacka, temp, 0, 0);
	ft_putstr_fd("pa\n", 1);
	return (0);
}

int	pb(t_stack *stacka, t_stack *stackb)
{
	int	temp;

	temp = stack_peek_top(stacka);
	if (stack_pop_top(stacka) < 0)
		return (-1);
	stack_push_top(stackb, temp, 0, 0);
	ft_putstr_fd("pb\n", 1);
	return (0);
}
