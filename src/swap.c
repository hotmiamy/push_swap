/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:22:20 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/15 04:27:59 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	swap_a(t_head *head_list)
{
	t_stack	*next_backup;

	next_backup = head_list->a->next;
	head_list->a->next = head_list->a->next->next;
	head_list->a->back = next_backup;
	next_backup->next = head_list->a;
	next_backup->back = NULL;
	head_list->a = head_list->a->back;
	if (head_list->psx_a == 0)
		head_list->psx_a++;
	else
		head_list->psx_a--;
	ft_printf("sa\n");
}

void	swap_b(t_head *head_list)
{
	t_stack	*next_backup;

	next_backup = head_list->b->next;
	head_list->b->next = head_list->b->next->next;
	head_list->b->back = next_backup;
	next_backup->next = head_list->b;
	next_backup->back = NULL;
	head_list->b = head_list->b->back;
	if (head_list->psx_b == 0)
		head_list->psx_b++;
	else
		head_list->psx_b--;
	ft_printf("sb\n");
}

void	swap_swap(t_head **head_lst)
{
	swap_a((*head_lst));
	swap_b((*head_lst));
	ft_printf("ss\n");
}
