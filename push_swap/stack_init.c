/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:44:22 by jpfannku          #+#    #+#             */
/*   Updated: 2021/12/30 14:24:44 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*list_create(int num, int pos_a, int pos_b)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->num = num;
	list->pos_a = pos_a;
	list->pos_b = pos_b;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_stack	*stack_create(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->bottom = NULL;
	stack->top = NULL;
	return (stack);
}

void	stack_destroy(t_stack *stack)
{
	while (stack != NULL && stack->bottom != NULL)
		stack_pop_bottom(stack);
	stack->bottom = NULL;
	stack->top = NULL;
	free(stack);
}

void	init_stack(t_ref *ref, t_stack *stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (stack_push_bottom(stack, ft_atoi_alt(argv[i], ref), 0, 0) < 0)
			error_msg();
		i++;
	}
}
