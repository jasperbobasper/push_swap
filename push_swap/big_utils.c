/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:43:47 by jpfannku          #+#    #+#             */
/*   Updated: 2021/12/30 13:33:22 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*dup_a(t_ref *ref)
{
	t_stack	*dupa;
	t_list	*temp;

	dupa = stack_create();
	temp = ref->stacka->top;
	while (temp != NULL)
	{
		if (stack_push_bottom(dupa, temp->num, 0, 0) < 0)
			error_msg();
		temp = temp->prev;
	}
	smallest_top(dupa, 'x');
	return (dupa);
}

void	smallest_top(t_stack *stack, char c)
{
	t_list	*temp;
	int		hold;
	int		idx;
	int		i;

	idx = 0;
	i = 0;
	temp = stack->top;
	hold = stack->top->num;
	while (temp != NULL)
	{
		if (temp->num < hold)
		{
			hold = temp->num;
			idx = i;
		}
		temp = temp->prev;
		i++;
	}
	if (idx <= i / 2)
		r_multiple(stack, idx, c);
	else
		rr_multiple(stack, i - idx, c);
}

void	set_zero(t_ref *ref)
{
	ref->ra = 0;
	ref->rb = 0;
	ref->rra = 0;
	ref->rrb = 0;
	ref->rrr = 0;
	ref->rrrr = 0;
}
