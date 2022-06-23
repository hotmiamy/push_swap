/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:00:57 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/23 01:11:13 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	three(t_head *lst)
{
	t_stack	*aux;
	int		max_size;

	aux = lst->a;
	lst->psx_a = 0;
	max_size = lst->a_size + lst->b_size;
	while (is_ordered(lst->a))
	{
		if (!aux)
		{
			aux = lst->a;
			lst->psx_a = 0;
		}
		if (aux->inx == lst->sml_a && lst->psx_a == lst->a_size / 2)
			swap_a(lst);
		if ((aux->inx == lst->sml_a && lst->psx_a == max_size - 1)
			|| (aux->inx == max_size && lst->psx_a == lst->a_size / 2))
			reverse_rotate_a(lst);
		if (aux->inx == max_size && lst->psx_a == 0)
			rotate_a(lst);
		aux = aux->next;
		lst->psx_a++;
	}
}

void	five(t_head *lst)
{
	t_stack	*aux;

	aux = lst->a;
	lst->psx_a = 0;
	while (lst->a_size != 3)
	{
		if (find_inx(&aux, lst, lst->sml_a) == 0)
		{
			if (aux->inx == lst->sml_a && lst->psx_a >= lst->a_size / 2)
				reverse_rotate_a(lst);
			else if (aux->inx == lst->sml_a && lst->psx_a < lst->a_size / 2)
				rotate_a(lst);
		}
		if (lst->a->inx == lst->sml_a)
			push_b(lst);
	}
	sort_three(lst);
	while (lst->b)
		push_a(lst);
}

void	sort_stack(t_head *lst)
{
	lst->psx_a = 0;
	if (lst->a_size == 2 && is_sorted(lst->a))
		swap_a(lst);
	if (lst->a_size <= 3 && is_sorted(lst->a))
		three(lst);
	if (lst->a_size <= 20 && is_sorted(lst->a))
		five(lst);
}
