/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:54:28 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/09 01:21:56 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	push_a(t_head *head_lst)
{
	t_stack	*aux_lst;

	if (!head_lst->stack_a)
	{
		head_lst->stack_a = head_lst->stack_b;
		head_lst->stack_b = head_lst->stack_b->next;
		head_lst->stack_b->back = NULL;
		head_lst->stack_a->next = NULL;
	}
	else if (head_lst->stack_b)
	{
		aux_lst = head_lst->stack_b;
		head_lst->stack_b = head_lst->stack_b->next;
		double_lstadd_front(&head_lst->stack_a, aux_lst);
	}
}

void	push_b(t_head *head_lst)
{
	t_stack	*aux_lst;

	if (!head_lst->stack_b)
	{
		head_lst->stack_b = head_lst->stack_a;
		head_lst->stack_a = head_lst->stack_a->next;
		head_lst->stack_a->back = NULL;
		head_lst->stack_b->next = NULL;
	}
	else if (head_lst->stack_a)
	{
		aux_lst = head_lst->stack_a;
		head_lst->stack_a = head_lst->stack_a->next;
		double_lstadd_front(&head_lst->stack_b, aux_lst);
	}
}
