/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 03:47:35 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/09 04:05:44 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	reverse_rotate_a(t_head *head_lst)
{
	t_stack	*new_top_node;

	new_top_node = psw_ft_lstlast(head_lst->stack_a);
	new_top_node->back->next = NULL;
	new_top_node->back = NULL;
	double_lstadd_front(&head_lst->stack_a, new_top_node);
}

void	reverse_rotate_b(t_head *head_lst)
{
	t_stack	*new_top_node;

	new_top_node = psw_ft_lstlast(head_lst->stack_b);
	new_top_node->back->next = NULL;
	new_top_node->back = NULL;
	double_lstadd_front(&head_lst->stack_b, new_top_node);
}

void	reverse_rotate_reverse_rotate(t_head **head_lst)
{
	reverse_rotate_a((*head_lst));
	reverse_rotate_b((*head_lst));
}
