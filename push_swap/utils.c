/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:03:22 by jpfannku          #+#    #+#             */
/*   Updated: 2021/12/31 13:16:38 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_peek_bottom(t_stack *stack)
{
	if (stack->bottom == NULL)
	{
		if (stack->top == NULL)
			return (-1);
		return (0);
	}
	return (stack->bottom->num);
}

int	stacksize(t_stack *stack)
{
	t_list	*temp;
	int		i;

	i = 1;
	temp = stack->top;
	if (temp == NULL)
		return (0);
	if (temp->prev == NULL)
		return (1);
	while (temp->prev != NULL)
	{
		temp = temp->prev;
		i++;
	}
	return (i);
}
