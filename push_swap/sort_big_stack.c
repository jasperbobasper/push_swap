/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:10:58 by jpfannku          #+#    #+#             */
/*   Updated: 2021/12/30 13:37:31 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_big_stack(t_ref *ref)
{
	int		*lis;
	int		i;

	ref->size = stacksize(ref->stacka);
	lis = init_lis(ref);
	i = 0;
	while (ref->size != ref->lis_sz)
	{
		while (ref->stacka->top->num != lis[i] && i < (ref->lis_sz - 1))
			i++;
		if ((i == (ref->lis_sz - 1)) && (ref->stacka->top->num != lis[i]))
		{
			pb(ref->stacka, ref->stackb);
			ref->size--;
		}	
		else
			ra_rb(ref->stacka, 'a');
		i = 0;
	}
	ref->sizeb = stacksize(ref->stackb);
	calc_moves(ref);
	smallest_top(ref->stacka, 'a');
	free(lis);
	return (0);
}
