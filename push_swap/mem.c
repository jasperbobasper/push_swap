/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:31:00 by jpfannku          #+#    #+#             */
/*   Updated: 2022/01/04 15:00:25 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_ref(t_ref *ref)
{
	stack_destroy(ref->stacka);
	free(ref->stackb);
}

void	makearray(int sz, t_stack *dupa, int *arr)
{
	int		i;
	t_list	*temp;

	temp = dupa->top;
	i = 0;
	while (i < sz)
	{
		arr[i] = temp->num;
		temp = temp->prev;
		i++;
	}
}

int	ft_atoi_alt(const char *str, t_ref *ref)
{
	int	val;
	int	x;
	int	neg;

	val = 0;
	x = 0;
	neg = 1;
	if (str[x] == '-')
	{
		neg = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		if ((val * 10 + str[x] - 48) >= 0)
			val = val * 10 + str[x] - 48;
		else
		{
			free_ref(ref);
			error_msg();
		}
		x++;
	}
	return (val * neg);
}

void	error_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	init_mem(t_ref *ref, int argc, char **argv)
{
	int	i;

	i = 0;
	ref->stacka = stack_create();
	ref->stackb = stack_create();
	init_stack(ref, ref->stacka, argc, argv);
	ref->size = argc - 1;
	ref->sizeb = 0;
	set_zero(ref);
}
