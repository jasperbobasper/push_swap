/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_moves_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:48:47 by jpfannku          #+#    #+#             */
/*   Updated: 2022/01/04 14:58:48 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_moves(t_ref *ref)
{
	int		best;
	t_stack	*moves;

	moves = stack_create();
	list_moves(ref, moves);
	while (ref->sizeb > 0)
	{
		best = best_move(ref, moves);
		do_best(best, ref, moves);
	}
	free(moves);
}

int	best_move(t_ref *ref, t_stack *moves)
{
	t_list	*temp;
	int		small;
	int		idx;
	int		hold;
	int		best;

	temp = moves->top;
	idx = 0;
	small = ref->sizeb;
	best = 0;
	while (idx < ref->sizeb)
	{
		hold = compare(temp->pos_a, temp->pos_b);
		if (hold < small)
		{
			small = hold;
			best = idx;
		}
		temp = temp->prev;
		idx++;
	}
	return (best);
}

void	update_best(int idx, t_ref *ref, t_stack *moves)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = moves->top;
	while (i < idx)
	{
		temp = temp->prev;
		i++;
	}
	if (temp->pos_a > -1)
		ref->ra = temp->pos_a;
	else
		ref->rra = (temp->pos_a * -1);
	if (temp->pos_b > -1)
		ref->rb = temp->pos_b;
	else
		ref->rrb = (temp->pos_b * -1);
	find_doubles(ref);
}

void	find_doubles(t_ref *ref)
{
	if (ref->ra >= ref->rb && ref->rb > 0)
	{
		ref->rrr = ref->rb;
		ref->ra = ref->ra - ref->rb;
		ref->rb = 0;
	}
	if (ref->rb >= ref->ra && ref->ra > 0)
	{
		ref->rrr = ref->ra;
		ref->rb = ref->rb - ref->ra;
		ref->ra = 0;
	}
	if (ref->rra >= ref->rrb && ref->rrb > 0)
	{
		ref->rrrr = ref->rrb;
		ref->rra = ref->rra - ref->rrb;
		ref->rrb = 0;
	}
	if (ref->rrb >= ref->rra && ref->rra > 0)
	{
		ref->rrrr = ref->rra;
		ref->rrb = ref->rrb - ref->rra;
		ref->rra = 0;
	}
}

void	do_best(int idx, t_ref *ref, t_stack *moves)
{
	update_best(idx, ref, moves);
	rrr_multiple(ref->stacka, ref->stackb, ref->rrr);
	rrrr_multiple(ref->stacka, ref->stackb, ref->rrrr);
	r_multiple(ref->stacka, ref->ra, 'a');
	r_multiple(ref->stackb, ref->rb, 'b');
	rr_multiple(ref->stacka, ref->rra, 'a');
	rr_multiple(ref->stackb, ref->rrb, 'b');
	pa(ref->stacka, ref->stackb);
	ref->size++;
	ref->sizeb--;
	stack_pop_bottom(moves);
	if (ref->sizeb > 0)
		change_moves(ref, moves);
	set_zero(ref);
}
