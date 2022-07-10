/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 01:04:48 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/10 03:47:38 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

t_stack	*max_closer(t_stack *top_b, t_head *lst, t_stack *stk_a)
{
	int		closer;
	int		pxs;
	t_stack	*closer_addr;

	pxs = 0;
	closer = 0;
	while (top_b)
	{
		if (top_b->inx > stk_a->inx)
		{
			if (closer == 0)
				closer = lst->max_b - stk_a->inx;
			if (top_b->inx - stk_a->inx <= closer)
			{
				closer = top_b->inx - stk_a->inx;
				closer_addr = top_b;
				lst->algo.pxs_b = pxs;
			}
		}
		top_b = top_b->next;
		pxs++;
	}
	return (closer_addr);
}

t_stack	*max_b_psx(int *b_pxs, t_stack *stk_b, t_head *lst)
{
	t_stack	*next;
	t_stack	*back;
	int		pxs;

	next = stk_b;
	back = psw_ft_lstlast(lst->b);
	pxs = 0;
	while (1)
	{
		if (next->inx == lst->max_b)
		{
			*b_pxs = pxs;
			return (next);
		}
		if (back->inx == lst->max_b)
		{
			*b_pxs = lst->b_size - pxs - 1;
			return (back);
		}
		next = next->next;
		back = back->back;
		pxs++;
	}
}

int	check_moves(t_head *lst, t_stack *stk_a, int *moves, t_stack **aux)
{
	if (stk_a->inx > lst->max_b)
	{
		*aux = max_b_psx(&lst->algo.pxs_b, lst->b, lst);
		if (lst->algo.pxs_b > lst->b_size / 2)
			*moves = number_moves(*moves, lst->b_size - lst->algo.pxs_b, lst);
		if (lst->algo.pxs_b <= lst->b_size / 2)
			*moves = number_moves(*moves, lst->algo.pxs_b, lst);
	}
	else
	{
		*aux = max_closer(lst->b, lst, stk_a);
		if (lst->algo.pxs_b > lst->b_size / 2)
			*moves = number_moves(*moves, lst->b_size - lst->algo.pxs_b - 1,
					lst);
		if (lst->algo.pxs_b <= lst->b_size / 2)
			*moves = number_moves(*moves, lst->algo.pxs_b + 1, lst);
	}
	return (*moves);
}

void	verify_moves(int moves, t_head *lst, t_stack *stk_a)
{
	t_stack	*aux;

	if (check_moves(lst, stk_a, &moves, &aux) <= lst->algo.less_move)
	{
		lst->algo.less_move = moves;
		lst->psx_a = lst->algo.pxs_a;
		lst->algo.best_a = stk_a;
		lst->algo.best_b = aux;
		lst->psx_b = lst->algo.pxs_b;
	}
}

void	best_a(t_head *lst, t_stack *stk_a)
{
	int		moves;

	moves = 1;
	lst->algo.pxs_a = 0;
	lst->algo.pxs_b = 0;
	lst->algo.less_move = __INT_MAX__;
	while (stk_a)
	{
		verify_moves(moves, lst, stk_a);
		stk_a = stk_a->next;
		lst->algo.pxs_a++;
		if (lst->algo.pxs_a <= lst->a_size / 2)
			moves++;
		else if (lst->algo.pxs_a > lst->a_size / 2)
			moves--;
	}
}
