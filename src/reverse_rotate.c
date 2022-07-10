/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 03:47:35 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/09 20:22:38 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	reverse_rotate_a(t_head *head_lst, t_bool print)
{
	t_stack	*new_top_node;

	new_top_node = psw_ft_lstlast(head_lst->a);
	new_top_node->back->next = NULL;
	new_top_node->back = NULL;
	double_lstadd_front(&head_lst->a, new_top_node);
	if (head_lst->psx_a == head_lst->a_size)
		head_lst->psx_a = 0;
	else
		head_lst->psx_a++;
	if (print == TRUE)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_head *head_lst, t_bool print)
{
	t_stack	*new_top_node;

	new_top_node = psw_ft_lstlast(head_lst->b);
	new_top_node->back->next = NULL;
	new_top_node->back = NULL;
	double_lstadd_front(&head_lst->b, new_top_node);
	if (head_lst->psx_b == head_lst->b_size)
		head_lst->psx_b = 0;
	else
		head_lst->psx_b++;
	if (print == TRUE)
		ft_printf("rrb\n");
}

void	reverse_rotate_reverse_rotate(t_head **head_lst)
{
	reverse_rotate_a((*head_lst), FALSE);
	reverse_rotate_b((*head_lst), FALSE);
	ft_printf("rrr\n");
}
