/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:13:23 by jpfannku          #+#    #+#             */
/*   Updated: 2021/12/29 18:13:49 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_push_top(t_stack *stack, int num, int pos_a, int pos_b)
{
	t_list	*list;

	list = list_create(num, pos_a, pos_b);
	list->prev = stack->top;
	stack->top = list;
	if (!list->prev)
	{
		if (stack->bottom != NULL)
			return (-1);
		stack->bottom = list;
	}
	else
		list->prev->next = list;
	return (0);
}

int	stack_push_bottom(t_stack *stack, int num, int pos_a, int pos_b)
{
	t_list	*list;

	list = list_create(num, pos_a, pos_b);
	if (!list)
		return (-1);
	list->next = stack->bottom;
	stack->bottom = list;
	if (!list->next)
	{
		if (stack->top != NULL)
			return (-1);
		stack->top = list;
	}
	else
		list->next->prev = list;
	return (0);
}

int	stack_pop_top(t_stack *stack)
{
	t_list	*temp;

	if (stack->top == NULL)
		return (-1);
	if (stack->top->next == NULL && stack->top->prev == NULL)
	{
		temp = stack->top;
		stack->top = NULL;
		stack->bottom = NULL;
		free(temp);
		return (0);
	}
	temp = stack->top;
	stack->top = stack->top->prev;
	stack->top->next = NULL;
	free(temp);
	return (0);
}

int	stack_pop_bottom(t_stack *stack)
{
	t_list	*temp;

	if (stack->bottom == NULL)
		return (-1);
	if (stack->bottom->next == NULL && stack->bottom->prev == NULL)
	{
		temp = stack->bottom;
		stack->bottom = NULL;
		stack->top = NULL;
		free(temp);
		return (0);
	}
	temp = stack->bottom;
	stack->bottom = stack->bottom->next;
	stack->bottom->prev = NULL;
	free(temp);
	return (0);
}

int	stack_peek_top(t_stack *stack)
{
	if (stack->top == NULL)
	{
		if (stack->bottom == NULL)
			return (-1);
		return (0);
	}
	return (stack->top->num);
}
