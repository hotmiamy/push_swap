/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:00:57 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/14 22:28:13 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	normalize(t_stack *lst, int lst_size, t_head *head)
{
	int		inx;
	t_stack	*aux_lst;

	inx = 1;
	aux_lst = lst->next;
	while (inx < lst_size)
	{
		while (aux_lst)
		{
			if (aux_lst->inx == 0)
				if (lst->content > aux_lst->content)
					lst = aux_lst;
			aux_lst = aux_lst->next;
		}
		lst->inx = inx;
		lst = head->a;
		aux_lst = lst->next;
		inx++;
	}
	while (lst)
	{
		if (lst->inx == 0)
			lst->inx = inx;
		lst = lst->next;
	}
}

int	is_sorted(t_stack *lst_a, t_stack *lst_b)
{
	t_stack	*aux;

	aux = lst_a->next;
	if (lst_b)
		return (1);
	while (aux)
	{
		if (lst_a->inx > aux->inx)
			return (1);
		lst_a = lst_a->next;
		aux = aux->next;
	}
	return (0);
}

void	sort_three(t_head *lst)
{
	if (lst->a->inx == 1 && lst->psx_a == lst->a_size)
		reverse_rotate_a(lst);
	else if (lst->a->inx == lst->a_size && lst->psx_a == 0)
		rotate_a(lst);
	else if (lst->a->inx == lst->a_size && lst->psx_a == lst->a_size / 2)
		swap_a(lst);
}

void	sort_stack(t_head *lst)
{
	t_stack	*aux_lst;

	lst->psx_a = 0;
	aux_lst = lst->a;
	if (lst->a_size == 2 && !is_sorted(lst->a, lst->b))
		swap_a(lst);
	if (lst->a_size <= 3)
	{
		while (is_sorted(aux_lst, lst->b))
		{
			if (!lst->a->next)
			{
				lst->a = aux_lst;
				lst->psx_a = 0;
			}
			sort_three(lst);
			aux_lst = lst->a;
			lst->a = lst->a->next;
			lst->psx_a++;
		}
		lst->a = aux_lst;
	}
}
