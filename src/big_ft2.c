/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_ft2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 03:46:11 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/10 03:47:41 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

int	bigger(int stk_a, int stk_b)
{
	if (stk_a > stk_b)
		return (stk_a);
	else
		return (stk_b);
}

int	number_moves(int moves_a, int moves_b, t_head *lst)
{
	if (lst->algo.pxs_a <= lst->a_size / 2
		&& lst->algo.pxs_b <= lst->b_size / 2)
		return (bigger(moves_a, moves_b));
	if (lst->algo.pxs_a > lst->a_size / 2
		&& lst->algo.pxs_b > lst->b_size / 2)
		return (bigger(moves_a, moves_b));
	else
		return (moves_a + moves_b);
}
