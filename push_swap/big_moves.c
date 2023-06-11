/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:49:33 by jpfannku          #+#    #+#             */
/*   Updated: 2022/01/04 14:58:01 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_a(int num, t_stack *stacka, t_ref *ref)
{
	int		i;
	int		j;
	int		big;
	t_list	*tempi;
	t_list	*tempj;

	i = 0;
	j = ref->size - 1;
	tempi = stacka->top;
	tempj = stacka->bottom;
	if (num > tempj->num && num < tempi->num)
		return (0);
	while (i <= (ref->size / 2) && j >= (ref->size / 2))
	{
		if (num > tempi->num && num < tempi->prev->num)
			return (i + 1);
		if (num < tempj->num && num > tempj->next->num)
			return ((i + 1) * -1);
		i++;
		j--;
		tempi = tempi->prev;
		tempj = tempj->next;
	}
	return (biggest_ind(stacka, ref));
}

int	biggest_ind(t_stack *stacka, t_ref *ref)
{
	int		i;
	int		j;
	int		big;
	t_list	*tempi;

	i = 0;
	j = 0;
	big = -2147483648;
	tempi = stacka->top;
	while (i < ref->size)
	{
		if (tempi->num > big)
		{
			big = tempi->num;
			j = i;
		}
		i++;
		tempi = tempi->prev;
	}
	if (j < (ref->size / 2))
		return (j + 1);
	else
		return (((ref->size - j) * -1) + 1);
}

void	list_moves(t_ref *ref, t_stack *moves)
{
	int		*arr;
	t_list	*tempb;
	int		idxa;
	int		idxb;

	ref->size = stacksize(ref->stacka);
	tempb = ref->stackb->top;
	idxb = 0;
	while (tempb != NULL)
	{
		idxa = pos_a(tempb->num, ref->stacka, ref);
		if (idxb < ref->sizeb / 2)
			stack_push_bottom(moves, 0, idxa, idxb);
		else
			stack_push_bottom(moves, 0, idxa, (ref->sizeb - idxb) * -1);
		idxb++;
		tempb = tempb->prev;
	}
}

void	change_moves(t_ref *ref, t_stack *moves)
{
	t_list	*tempb;
	t_list	*temp;
	int		idxa;
	int		idxb;

	tempb = ref->stackb->top;
	temp = moves->top;
	idxb = 0;
	while (tempb != NULL)
	{
		idxa = pos_a(tempb->num, ref->stacka, ref);
		temp->pos_a = idxa;
		if (idxb < ref->sizeb / 2)
			temp->pos_b = idxb;
		else
			temp->pos_b = (ref->sizeb - idxb) * -1;
		idxb++;
		tempb = tempb->prev;
		temp = temp->prev;
	}
}

int	compare(int a, int b)
{
	int	hold;

	if (a > -1 && b > -1)
	{
		if (a > b)
			hold = a;
		else
			hold = b;
	}
	if (a < 0 && b < 0)
	{
		if (a < b)
			hold = a * -1;
		else
			hold = b * -1;
	}
	if (a > -1 && b < 0)
		hold = (b * -1) + a;
	if (b > -1 && a < 0)
		hold = (a * -1) + b;
	return (hold);
}
