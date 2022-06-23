/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:34:09 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/23 03:58:04 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

int	can_pb(int who_is, t_head *lst, t_stack *bttm)
{
	if (who_is == FRT)
		if (lst->a->inx < lst->max_b && lst->a->inx > lst->sml_b)
			return (1);
	else if (who_is == LAST)
		if (bttm->inx < lst->max_b && lst->a->inx > lst->sml_b)
			return (1);
	return (0);
}

void	move_tob(t_head *lst, int who_is)
{
	if (!can_pb(who_is, lst, psw_ft_lstlast(lst))
		
}

int	who_pb(t_head *lst)
{
	t_stack	*head;
	t_stack	*bttm;

	head = lst->a;
	bttm = psw_ft_lstlast(lst);
	if (head->inx < bttm->inx)
		move_tob(lst, FRT);
	else if (bttm->inx < head->inx)
		move_tob(lst, LAST);
}

void	big_sort(t_head *lst)
{
	while (is_ordered(lst))
	{
		
	}
}
