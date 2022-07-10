/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:00:57 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/09 20:29:11 by llopes-n         ###   ########.fr       */
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
			swap_a(lst, TRUE);
		if ((aux->inx == lst->sml_a && lst->psx_a == max_size - 1)
			|| (aux->inx == max_size && lst->psx_a == lst->a_size / 2))
			reverse_rotate_a(lst, TRUE);
		if (aux->inx == max_size && lst->psx_a == 0)
			rotate_a(lst, TRUE);
		aux = aux->next;
		lst->psx_a++;
	}
}

void	five(t_head *lst)
{
	t_stack	*aux;

	lst->psx_a = 0;
	while (lst->a_size != 3)
	{
		aux = find_inx(lst->a, &lst->psx_a, lst->sml_a);
		while (aux->back)
		{
			if (aux->inx == lst->sml_a && lst->psx_a <= lst->a_size / 2)
				rotate_a(lst, TRUE);
			else if (aux->inx == lst->sml_a && lst->psx_a > lst->a_size / 2)
				reverse_rotate_a(lst, TRUE);
		}
		if (lst->a->inx == lst->sml_a)
			push_b(lst);
	}
	three(lst);
	while (lst->b)
		push_a(lst);
}

void	sort_stack(t_head *lst)
{
	lst->psx_a = 0;
	if (lst->a_size == 2 && is_ordered(lst->a) == FALSE)
		swap_a(lst, TRUE);
	if (lst->a_size <= 3 && is_ordered(lst->a) == FALSE)
		three(lst);
	if (lst->a_size <= 7 && is_ordered(lst->a) == FALSE)
		five(lst);
}
