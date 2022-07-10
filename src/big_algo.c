/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:34:09 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/09 22:38:10 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	move_best(t_head *lst)
{
	while (lst->algo.best_a->back && lst->algo.best_b->next)
	{
		if (lst->psx_a <= lst->a_size / 2 && lst->psx_b <= lst->b_size / 2)
			rotate_rotate(&lst);
		else if (lst->psx_a >= lst->a_size / 2 && lst->psx_b >= lst->b_size / 2)
			reverse_rotate_reverse_rotate(&lst);
		else
			break ;
	}
	while (lst->algo.best_a->back)
	{
		if (lst->psx_a <= lst->a_size / 2)
			rotate_a(lst, TRUE);
		else if (lst->psx_a >= lst->a_size / 2)
			reverse_rotate_a(lst, TRUE);
	}
	while (lst->algo.best_b->next)
	{
		if (lst->psx_b <= lst->b_size / 2)
			rotate_b(lst, TRUE);
		else if (lst->psx_b >= lst->b_size / 2)
			reverse_rotate_b(lst, TRUE);
	}
}

void	move_best_top(t_head *lst)
{
	while (lst->algo.best_a->back && lst->algo.best_b->back)
	{
		if (lst->psx_a <= lst->a_size / 2 && lst->psx_b <= lst->b_size / 2)
			rotate_rotate(&lst);
		else if (lst->psx_a >= lst->a_size / 2 && lst->psx_b >= lst->b_size / 2)
			reverse_rotate_reverse_rotate(&lst);
		else
			break ;
	}
	while (lst->algo.best_a->back)
	{
		if (lst->psx_a <= lst->a_size / 2)
			rotate_a(lst, TRUE);
		else if (lst->psx_a >= lst->a_size / 2)
			reverse_rotate_a(lst, TRUE);
	}
	while (lst->algo.best_b->back)
	{
		if (lst->psx_b <= lst->b_size / 2)
			rotate_b(lst, TRUE);
		else if (lst->psx_b >= lst->b_size / 2)
			reverse_rotate_b(lst, TRUE);
	}
}

void	max_top(t_head *lst, t_stack *stk_a_b, int lst_size, t_bool is_a)
{
	int		max;
	int		psx;

	psx = 0;
	max = find_big_or_small(stk_a_b, TRUE);
	while (stk_a_b->inx != max)
	{
		stk_a_b = stk_a_b->next;
		psx++;
	}
	while (stk_a_b->back)
	{
		if (psx <= lst_size / 2 && is_a == FALSE)
			rotate_b(lst, TRUE);
		else if (psx > lst_size / 2 && is_a == FALSE)
			reverse_rotate_b(lst, TRUE);
		else if (psx > lst_size / 2 && is_a == TRUE)
			reverse_rotate_a(lst, TRUE);
		else if (psx <= lst_size / 2 && is_a == TRUE)
			rotate_a(lst, TRUE);
	}
}

void	find_best(t_head *lst)
{
	t_stack	*bttm;

	bttm = psw_ft_lstlast(lst->b);
	if ((lst->b->inx > lst->a->inx && bttm->inx < lst->a->inx)
		|| (lst->b->inx > lst->a->inx || bttm->inx < lst->a->inx))
	{
		best_a(lst, lst->a);
		if (lst->algo.best_a->inx > lst->max_b)
			move_best_top(lst);
		else
			move_best(lst);
	}
	push_b(lst);
}

void	big_sort(t_head *lst)
{
	lst->psx_a = 0;
	if (!lst->b && is_ordered(lst->a) == FALSE)
		run_nmoves(2, PB, lst);
	while (is_ordered(lst->a) == FALSE || lst->b != NULL)
	{
		if ((lst->a->inx > lst->max_b || lst->a->inx < lst->sml_b)
			&& lst->b->inx == lst->max_b)
			push_b(lst);
		else
			find_best(lst);
		if (!lst->a)
		{
			max_top(lst, lst->b, lst->b_size, FALSE);
			while (lst->b)
				push_a(lst);
		}
	}
}
