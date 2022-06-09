/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:22:20 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/09 00:33:00 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	swap_a(t_head *head_list)
{
	t_stack	*next_backup;

	next_backup = head_list->stack_a->next;
	head_list->stack_a->next = head_list->stack_a->next->next;
	head_list->stack_a->back = next_backup;
	next_backup->next = head_list->stack_a;
	next_backup->back = NULL;
	head_list->stack_a = head_list->stack_a->back;
}

void	swap_b(t_head *head_list)
{
	t_stack	*next_backup;

	next_backup = head_list->stack_b->next;
	head_list->stack_b->next = head_list->stack_b->next->next;
	head_list->stack_b->back = next_backup;
	next_backup->next = head_list->stack_b;
	next_backup->back = NULL;
	head_list->stack_b = head_list->stack_b->back;
}

void	swap_swap(t_head **head_lst)
{
	swap_a((*head_lst));
	swap_b((*head_lst));
}
