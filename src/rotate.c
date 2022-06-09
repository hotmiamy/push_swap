/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:24:41 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/09 03:56:28 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	rotate_a(t_head *head_lst)
{
	t_stack	*new_last_node;

	new_last_node = head_lst->stack_a;
	head_lst->stack_a = head_lst->stack_a->next;
	new_last_node->next = NULL;
	head_lst->stack_a->back = NULL;
	double_lstadd_back(&head_lst->stack_a, new_last_node);
}

void	rotate_b(t_head *head_lst)
{
	t_stack	*new_last_node;

	new_last_node = head_lst->stack_b;
	head_lst->stack_b = head_lst->stack_b->next;
	new_last_node->next = NULL;
	head_lst->stack_b->back = NULL;
	double_lstadd_back(&head_lst->stack_b, new_last_node);
}

void	rotate_rotate(t_head **head_lst)
{
	rotate_a((*head_lst));
	rotate_b((*head_lst));
}
