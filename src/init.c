/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 08:29:35 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/15 08:58:56 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

int	*check_double(int *stack, int size)
{
	int	inx;
	int	jnx;

	inx = 0;
	while (inx < size)
	{
		jnx = inx + 1;
		while (jnx < size)
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

int	check_size(char **argv)
{
	int	inx;
	int	jnx;
	int	size;

	inx = 1;
	size = 0;
	while (argv[inx])
	{
		jnx = 0;
		while (argv[inx][jnx])
		{
			if (argv[inx][jnx] != ' ')
			{
				size++;
				while (argv[inx][jnx] != ' ' && argv[inx][jnx])
					jnx++;
			}
			else
				jnx++;
		}
		inx++;
	}
	return (size);
}

int	*check_args(char **argv, t_head *lst)
{
	int	*array;
	int	arr_inx;
	int	arg_y;

	lst->a_size = check_size(argv);
	array = malloc(lst->a_size * sizeof(int));
	arr_inx = 0;
	arg_y = 0;
	while (argv[++arg_y])
	{
		if (ft_smart_isdigit(argv[arg_y]) != 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		array[arr_inx] = ft_atoi(argv[arg_y]);
		arr_inx++;
	}
	check_double(array, lst->a_size);
	return (array);
}

t_head	*init(char **argv)
{
	t_head	*lst;

	lst = (t_head *)malloc(sizeof(t_head));
	lst->b_size = 0;
	lst->sml_a = 1;
	lst->sml_b = 0;
	creat_doublelst(check_args(argv, lst), lst);
	return (lst);
}
