/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:58:23 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/09 04:10:29 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

int	*check_double(int *stack)
{
	int	inx;
	int	jnx;

	inx = 0;
	while (stack[inx])
	{
		jnx = inx + 1;
		while (stack[jnx])
		{
			if (stack[inx] == stack[jnx])
			{
				write(2, "Error\n", 6);
				exit(2);
			}
			jnx++;
		}
		inx++;
	}
	return (stack);
}

int	*check_args(char **argv, int argc)
{
	int	*array;
	int	arr_inx;
	int	arg_y;
	int	arg_x;

	array = malloc(argc - 1 * sizeof(int));
	arr_inx = 0;
	arg_y = 0;
	while (argv[++arg_y])
	{
		arg_x = 0;
		while (argv[arg_y][arg_x])
		{
			if (ft_isdigit(argv[arg_y][arg_x]) == 0)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			arg_x++;
		}
		array[arr_inx] = ft_atoi(argv[arg_y]);
		arr_inx++;
	}
	check_double(array);
	return (array);
}

int	main(int argc, char **argv)
{
	t_head	*stack;

	stack = creat_doublelst(check_args(argv, argc));
	return (0);
}
