/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:16:32 by jpfannku          #+#    #+#             */
/*   Updated: 2021/12/31 13:03:43 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (i < argc)
	{
		while (j < argc)
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[j])) == 0)
			{
				if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
					error_msg();
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	check_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (argv[i][j] == '-')
		{
			if (!argv[i][j + 1])
				error_msg();
			j++;
		}
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				error_msg();
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	in_order(t_stack *stack)
{
	t_list	*temp;

	temp = stack->top->prev;
	while (temp != NULL)
	{
		if (temp->next->num < temp->num)
			temp = temp->prev;
		else
			return (0);
	}
	return (-1);
}

int	rev_order(t_stack *stack)
{
	t_list	*temp;

	temp = stack->top->prev;
	while (temp != NULL)
	{
		if (temp->next->num > temp->num)
			temp = temp->prev;
		else
			return (0);
	}
	return (-1);
}

void	sort_rev(t_ref *ref)
{
	ref->size = stacksize(ref->stacka);
	while (ref->size > 0)
	{
		pb(ref->stacka, ref->stackb);
		ref->size--;
	}
	ref->sizeb = stacksize(ref->stackb);
	while (ref->sizeb > 0)
	{
		rra_rrb(ref->stackb, 'b');
		pa(ref->stacka, ref->stackb);
		ref->sizeb--;
	}
	free_ref(ref);
	exit(0);
}
