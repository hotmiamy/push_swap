/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:24:41 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/14 20:18:12 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	rotate_a(t_head *head_lst)
{
	t_stack	*new_last_node;

	new_last_node = head_lst->a;
	head_lst->a = head_lst->a->next;
	new_last_node->next = NULL;
	head_lst->a->back = NULL;
	double_lstadd_back(&head_lst->a, new_last_node);
	ft_printf("ra\n");
}

void	rotate_b(t_head *head_lst)
{
	t_stack	*new_last_node;

	new_last_node = head_lst->b;
	head_lst->b = head_lst->b->next;
	new_last_node->next = NULL;
	head_lst->b->back = NULL;
	double_lstadd_back(&head_lst->b, new_last_node);
	ft_printf("rb\n");
}

void	rotate_rotate(t_head **head_lst)
{
	rotate_a((*head_lst));
	rotate_b((*head_lst));
	ft_printf("rr\n");
}
