/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:54:28 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/23 01:15:05 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	push_a(t_head *head_lst)
{
	t_stack	*aux_lst;

	if (head_lst->psx_b > 0)
		head_lst->psx_b--;
	if (head_lst->b->inx == head_lst->sml_b)
		find_big_or_small(head_lst->b, head_lst->sml_b, SMALL);
	if (head_lst->b->inx == head_lst->max_b)
		find_big_or_small(head_lst->b, head_lst->max_b, BIG);
	aux_lst = head_lst->b;
	head_lst->b = head_lst->b->next;
	if (!head_lst->b)
	{
		head_lst->sml_b = 0;
		head_lst->max_b = 0;
	}
	if (head_lst->b)
		head_lst->b->back = NULL;
	double_lstadd_front(&head_lst->a, aux_lst);
	if (!head_lst->a->next)
		head_lst->sml_a = head_lst->a->inx;
	else if (head_lst->a->inx < head_lst->sml_a)
		head_lst->sml_a = head_lst->a->inx;
	head_lst->a_size++;
	head_lst->b_size--;
	ft_printf("pa\n");
}

void	push_b(t_head *head_lst)
{
	t_stack	*aux_lst;

	if (head_lst->psx_a > 0)
		head_lst->psx_a--;
	if (head_lst->a->inx == head_lst->sml_a)
		find_big_or_small(head_lst->a, head_lst->sml_a, SMALL);
	aux_lst = head_lst->a;
	head_lst->a = head_lst->a->next;
	if (!head_lst->a)
		head_lst->sml_a = 0;
	if (head_lst->a)
		head_lst->a->back = NULL;
	double_lstadd_front(&head_lst->b, aux_lst);
	if (!head_lst->b->next)
	{
		head_lst->sml_b = head_lst->b->inx;
		head_lst->max_b = head_lst->b->inx;
	}
	else if (head_lst->b->inx < head_lst->sml_b)
		head_lst->sml_b = head_lst->b->inx;
	else if (head_lst->b->inx > head_lst->max_b)
		head_lst->max_b = head_lst->b->inx;
	head_lst->a_size--;
	head_lst->b_size++;
	ft_printf("pb\n");
}
