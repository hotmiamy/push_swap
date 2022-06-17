/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:58:23 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/16 04:37:57 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

int	main(int argc, char **argv)
{
	t_head	*stack;

	stack = init(argv, argc - 1);
	normalize(stack->a, stack->a_size, stack);
	sort_stack(stack);
	free_stack(&stack);
	return (0);
}
