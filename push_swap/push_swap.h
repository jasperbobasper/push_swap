/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:08:15 by jpfannku          #+#    #+#             */
/*   Updated: 2022/01/04 15:11:05 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_list
{
	int				num;
	int				pos_a;
	int				pos_b;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	struct s_list	*top;
	struct s_list	*bottom;
}	t_stack;

typedef struct s_lis
{
	int				val;
	int				len;
	struct s_lis	*next;
}	t_lis;

typedef struct s_ref
{
	struct s_stack	*stacka;
	struct s_stack	*stackb;
	struct s_stack	*moves;
	int				*lis;
	int				lis_sz;
	int				size;
	int				sizeb;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rrr;
	int				rrrr;
}	t_ref;

void	push_swap(int argc, char **argv);

/*init & check & mem*/
void	init_mem(t_ref *ref, int argc, char **argv);
int		check_dup(int argc, char **argv);
int		check_valid(int argc, char **argv);
void	error_msg(void);
void	free_ref(t_ref *ref);
int		ft_atoi_alt(const char *str, t_ref *ref);
int		in_order(t_stack *stack);
int		rev_order(t_stack *stack);
void	sort_rev(t_ref *ref);

/*stack utils*/
t_list	*list_create(int num, int pos_a, int pos_b);
t_stack	*stack_create(void);
int		stacksize(t_stack *stack);
void	stack_destroy(t_stack *stack);
int		stack_push_top(t_stack *stack, int num, int pos_a, int pos_b);
int		stack_push_bottom(t_stack *stack, int num, int pos_a, int pos_b);
int		stack_pop_top(t_stack *stack);
int		stack_pop_bottom(t_stack *stack);
int		stack_peek_top(t_stack *stack);
int		stack_peek_bottom(t_stack *stack);
void	init_stack(t_ref *ref, t_stack *stack, int argc, char **argv);
void	stack_size(t_ref *ref);

/*push_swap moves*/
int		sa_sb(t_stack *stacka, char c);
int		ss(t_stack *stacka, t_stack *stackb);
int		pa(t_stack *stacka, t_stack *stackb);
int		pb(t_stack *stacka, t_stack *stackb);
int		ra_rb(t_stack *stack, char c);
int		rra_rrb(t_stack *stack, char c);
int		rr(t_stack *stacka, t_stack *stackb);
int		rrr(t_stack *stacka, t_stack *stackb);
int		rr_multiple(t_stack *stack, int num, char c);
int		r_multiple(t_stack *stack, int num, char c);
int		rrr_multiple(t_stack *stacka, t_stack *stackb, int num);
int		rrrr_multiple(t_stack *stacka, t_stack *stackb, int num);

/*sort*/

int		two_num(t_stack *stack);
int		three_num(int sz, t_stack *stack, char c);
int		four_num(t_stack *sta, t_stack *stb);
int		five_num(int sz, t_stack *sta, t_stack *stb);
int		sort_big_stack(t_ref *ref);

/*lis*/
void	make_lis(t_ref *ref, int *v, int len, t_lis *lis);
int		*init_lis(t_ref *ref);
void	makearray(int sz, t_stack *dupa, int *arr);
void	lisarray(t_ref *ref, t_lis *lis, int *arr);
t_stack	*dup_a(t_ref *ref);
void	lis_size(t_lis *lis, t_ref *ref);
void	best_lis(t_lis *n, int len);

/*big stack utils*/
void	smallest_top(t_stack *stack, char c);
void	calc_moves(t_ref *ref);
int		best_move(t_ref *ref, t_stack *move);
int		compare(int a, int b);
void	do_best(int idx, t_ref *ref, t_stack *moves);
void	set_zero(t_ref *ref);
void	update_best(int idx, t_ref *ref, t_stack *moves);
int		pos_a(int num, t_stack *stacka, t_ref *ref);
void	list_moves(t_ref *ref, t_stack *stack);
void	change_moves(t_ref *ref, t_stack *moves);
void	find_doubles(t_ref *ref);
int		biggest_ind(t_stack *stacka, t_ref *ref);

#endif