/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:54:28 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/13 23:42:13 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	push_a(t_head *head_lst)
{
	t_stack	*aux_lst;

	if (!head_lst->a)
	{
		head_lst->a = head_lst->b;
		head_lst->b = head_lst->b->next;
		head_lst->b->back = NULL;
		head_lst->a->next = NULL;
	}
	else
	{
		aux_lst = head_lst->b;
		head_lst->b = head_lst->b->next;
		double_lstadd_front(&head_lst->a, aux_lst);
	}
	head_lst->a_size++;
	head_lst->b_size--;
	ft_printf("pa\n");
}

void	push_b(t_head *head_lst)
{
	t_stack	*aux_lst;

	if (!head_lst->b)
	{
		head_lst->b = head_lst->a;
		head_lst->a = head_lst->a->next;
		head_lst->a->back = NULL;
		head_lst->b->next = NULL;
	}
	else
	{
		aux_lst = head_lst->a;
		head_lst->a = head_lst->a->next;
		double_lstadd_front(&head_lst->b, aux_lst);
	}
	head_lst->a_size--;
	head_lst->b_size++;
	ft_printf("pb\n");
}
