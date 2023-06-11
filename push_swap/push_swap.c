/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:18:08 by jpfannku          #+#    #+#             */
/*   Updated: 2022/01/04 14:59:32 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_ref	ref;

	if (argc < 3)
		exit(0);
	check_dup(argc, argv);
	check_valid(argc, argv);
	init_mem(&ref, argc, argv);
	stack_size(&ref);
}

void	stack_size(t_ref *ref)
{
	if (in_order(ref->stacka) < 0)
	{
		free_ref(ref);
		exit(0);
	}
	if (ref->size <= 3)
		three_num(ref->size, ref->stacka, 'a');
	if (ref->size == 5 || ref->size == 4)
		five_num(ref->size, ref->stacka, ref->stackb);
	if (rev_order(ref->stacka) < 0)
		sort_rev(ref);
	if (ref->size > 5)
		sort_big_stack(ref);
	free_ref(ref);
}
