/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:54:28 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/09 21:10:52 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	push_a(t_head *lst)
{
	t_stack	*aux_lst;

	if (lst->psx_b > 0)
		lst->psx_b--;
	if (lst->b->inx == lst->sml_b && lst->b->next)
		lst->sml_b = find_big_or_small(lst->b->next, FALSE);
	if (lst->b->inx == lst->max_b && lst->b->next)
		lst->max_b = find_big_or_small(lst->b->next, TRUE);
	aux_lst = lst->b;
	lst->b = lst->b->next;
	if (!lst->b)
	{
		lst->sml_b = 0;
		lst->max_b = 0;
	}
	if (lst->b)
		lst->b->back = NULL;
	double_lstadd_front(&lst->a, aux_lst);
	if (!lst->a->next)
		lst->sml_a = lst->a->inx;
	else if (lst->a->inx < lst->sml_a)
		lst->sml_a = lst->a->inx;
	lst->a_size++;
	lst->b_size--;
	ft_printf("pa\n");
}

void	push_b(t_head *lst)
{
	t_stack	*aux_lst;

	if (lst->psx_a > 0)
		lst->psx_a--;
	if (lst->a->inx == lst->sml_a && lst->a->next)
		lst->sml_a = find_big_or_small(lst->a->next, FALSE);
	aux_lst = lst->a;
	lst->a = lst->a->next;
	if (!lst->a)
		lst->sml_a = 0;
	if (lst->a)
		lst->a->back = NULL;
	double_lstadd_front(&lst->b, aux_lst);
	if (!lst->b->next)
	{
		lst->sml_b = lst->b->inx;
		lst->max_b = lst->b->inx;
	}
	else if (lst->b->inx < lst->sml_b)
		lst->sml_b = lst->b->inx;
	else if (lst->b->inx > lst->max_b)
		lst->max_b = lst->b->inx;
	lst->a_size--;
	lst->b_size++;
	ft_printf("pb\n");
}
