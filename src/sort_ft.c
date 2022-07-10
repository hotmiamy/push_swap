/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:24:52 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/09 21:09:55 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

/**
 * @brief index numbers from smallest to largest
 */
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

/**
*	@brief A boolean function to determine if stack is ordered
*/
t_bool	is_ordered(t_stack *lst)
{
	t_stack	*aux;

	aux = lst->next;
	while (aux)
	{
		if (lst->inx > aux->inx)
			return (FALSE);
		lst = lst->next;
		aux = aux->next;
	}
	return (TRUE);
}

/**
* @brief Find the biggest and the smaller indexs in stack A or B, 
*		 i just use when i push something.
*/
int	find_big_or_small(t_stack *a_b, t_bool big)
{
	t_stack	*stack;
	int		max_small;

	stack = a_b;
	max_small = a_b->inx;
	while (stack)
	{
		if (big == TRUE)
		{
			if (stack->inx > max_small)
				max_small = stack->inx;
		}
		else
		{
			if (stack->inx < max_small)
				max_small = stack->inx;
		}
		stack = stack->next;
	}
	return (max_small);
}

/**
 * @brief Run moves N times
 * 
 */
void	run_nmoves(int n, int move, t_head *lst)
{
	while (n--)
	{
		if (move == PA)
			push_a(lst);
		else if (move == PB)
			push_b(lst);
		else if (move == RA)
			rotate_a(lst, TRUE);
		else if (move == RB)
			rotate_b(lst, TRUE);
		else if (move == RR)
			rotate_rotate(&lst);
		else if (move == RRA)
			reverse_rotate_a(lst, TRUE);
		else if (move == RRB)
			reverse_rotate_b(lst, TRUE);
		else if (move == RRR)
			reverse_rotate_reverse_rotate(&lst);
		else if (move == SA)
			swap_a(lst, TRUE);
		else if (move == SB)
			swap_b(lst, TRUE);
		else if (move == SS)
			swap_swap(&lst);
	}
}

/**
 * @brief Find a index in the stack 
 * 
 */
t_stack	*find_inx(t_stack *inx_addr, int *psx, int inx)
{
	while (inx_addr->inx != inx && inx_addr->next)
	{
		inx_addr = inx_addr->next;
		*psx = *psx + 1;
	}
	return (inx_addr);
}
