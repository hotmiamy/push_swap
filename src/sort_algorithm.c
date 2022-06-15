/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:00:57 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/15 06:36:17 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	sort_three(t_head *lst)
{
	t_stack	*aux;
	int		max_size;

	aux = lst->a;
	max_size = lst->a_size + lst->b_size;
	lst->psx_a = 0;
	while (is_sorted(lst->a))
	{
		if (aux->inx == lst->sml_a && lst->psx_a == lst->a_size)
			reverse_rotate_a(lst);
		else if (aux->inx == max_size && lst->psx_a == 0)
			rotate_a(lst);
		else if ((aux->inx == max_size || aux->inx == lst->sml_a)
			&& lst->psx_a == lst->a_size / 2)
			swap_a(lst);
		cant_next(&aux, lst);
	}
}

void	sort_five(t_head *lst)
{
	t_stack	*aux;

	aux = lst->a;
	lst->psx_a = 0;
	while (lst->a_size != 3)
	{
		if (lst->a->inx == 1 || lst->a->inx == 2)
			push_b(lst);
		if (aux->inx == lst->sml_a && lst->psx_a >= lst->a_size / 2)
			reverse_rotate_a(lst);
		else if (aux->inx == lst->sml_a && lst->psx_a <= lst->a_size / 2)
			rotate_a(lst);
		cant_next(&aux, lst);
	}
	sort_three(lst);
	while (lst->b)
		push_a(lst);
}

void	sort_stack(t_head *lst)
{
	if (lst->a_size == 2 && is_sorted(lst->a))
		swap_a(lst);
	if (lst->a_size <= 3 && is_sorted(lst->a))
		sort_three(lst);
	if (lst->a_size <= 5 && is_sorted(lst->a))
		sort_five(lst);
}
