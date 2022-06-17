/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:29:30 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/16 02:23:44 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	psw_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	exit_clean(int *stack)
{
	free(stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_head **lst)
{
	t_stack	*aux;

	while ((*lst)->a)
	{
		aux = (*lst)->a->next;
		free((*lst)->a);
		(*lst)->a = aux;
	}
	free(*lst);
}

void	free_lst_exit(t_head **lst)
{
	free(*lst);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_str(char **str)
{
	int	inx;

	inx = 0;
	while (str[inx])
	{
		free(str[inx]);
		inx++;
	}
	free(str);
}
