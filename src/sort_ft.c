/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:24:52 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/23 01:10:47 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	normalize(t_stack *lst, int lst_size, t_head *head)
{
	int		inx;
	t_stack	*aux_lst;

	inx = 1;
	aux_lst = lst->next;
	while (inx <= lst_size)
	{
		while (aux_lst)
		{
			if (lst->inx != 0)
				while (lst->inx != 0 && lst->next)
					lst = lst->next;
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
}

/*
	A boolean function to determine if stack is ordered
 */

int	is_ordered(t_stack *lst)
{
	t_stack	*aux;

	aux = lst->next;
	while (aux)
	{
		if (lst->inx > aux->inx)
			return (1);
		lst = lst->next;
		aux = aux->next;
	}
	return (0);
}

/* 
	I created this funtion to find the biggest and the smaller indexs 
	in stack A or B, i just use when i push something.
*/

void	find_big_or_small(t_stack *a_b, int max_small, int big_small)
{
	t_stack	*stack;

	stack = a_b;
	while (stack)
	{
		if (big_small == BIG)
		{
			if (stack->inx > a_b->inx)
				max_small = stack->inx;
			else
				max_small = a_b->inx;
		}
		else
		{
			if (stack->inx < a_b->inx)
				max_small = stack->inx;
			else
				max_small = a_b->inx;
		}
		stack = stack->next;
	}
}

int	find_inx(t_stack **next_addr, t_head *head, int inx)
{
	if (!(*next_addr)->next)
	{
		*next_addr = head->a;
		head->psx_a = 0;
	}
	while ((*next_addr)->inx != inx && (*next_addr)->next)
	{
		*next_addr = (*next_addr)->next;
		head->psx_a++;
	}
	if ((*next_addr)->inx == inx)
		return (0);
	return (1);
}
