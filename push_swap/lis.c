/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:33:45 by jpfannku          #+#    #+#             */
/*   Updated: 2022/01/04 14:59:16 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lisarray(t_ref *ref, t_lis *lis, int *arr)
{
	int		i;
	t_lis	*temp;

	temp = lis;
	i = 0;
	while (i < ref->lis_sz)
	{
		arr[i] = temp->val;
		temp = temp->next;
		i++;
	}
}

int	*init_lis(t_ref *ref)
{
	int		*arr;
	int		*lisarr;
	t_lis	*lis;
	t_stack	*dupa;

	dupa = dup_a(ref);
	arr = (int *)malloc(sizeof(int) * (ref->size));
	makearray(ref->size, dupa, arr);
	lis = ft_calloc(ref->size, sizeof(t_lis));
	make_lis(ref, arr, ref->size, lis);
	lis_size(lis, ref);
	lisarr = (int *)malloc(sizeof(int) * ref->lis_sz);
	stack_destroy(dupa);
	free(arr);
	lisarray(ref, lis, lisarr);
	free(lis);
	return (lisarr);
}

void	make_lis(t_ref *ref, int *v, int len, t_lis *n)
{
	int		i;
	t_lis	*p;

	i = 0;
	while (i < len)
	{
		n[i].val = v[i];
		i++;
	}
	while (i >= 0)
	{
		p = n + i;
		while (p < n + len)
		{
			if (p->val > n[i].val && p->len >= n[i].len)
			{
				n[i].next = p;
				n[i].len = p->len + 1;
			}
			p++;
		}
		i--;
	}
	best_lis(n, len);
}

void	best_lis(t_lis *n, int len)
{
	t_lis	*p;
	int		i;

	p = n;
	i = 0;
	while (i < len)
	{
		if (n[i].len > p->len)
			p = n + i;
		i++;
	}
}

void	lis_size(t_lis *lis, t_ref *ref)
{
	t_lis	*temp;
	int		sz;

	temp = lis;
	sz = 0;
	while (temp->next)
	{
		sz++;
		temp = temp->next;
	}
	ref->lis_sz = sz;
}
