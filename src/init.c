/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 08:29:35 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/09 22:21:02 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	check_double(int *stack, int size, t_head *lst)
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
				free(stack);
				free_lst_exit(&lst);
			}
			jnx++;
		}
		inx++;
	}
}

int	check_size(char **argv)
{
	int	inx;
	int	jnx;
	int	size;

	inx = 0;
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

int	is_string(char **argv, t_head *lst)
{
	int	inx;
	int	jnx;

	inx = 0;
	while (argv[inx])
	{
		if (ft_string_isdigit(argv[inx]) != 0)
			free_lst_exit(&lst);
		inx++;
	}
	inx = 0;
	jnx = 0;
	while (argv[inx][jnx])
	{
		if (argv[inx][jnx] == ' ')
			return (0);
		jnx++;
	}
	return (1);
}

int	*fill_stack(char **argv, t_head *lst, int argc)
{
	int		inx;
	int		*array;
	char	**new_arg;

	if (is_string(argv, lst) == 0)
		new_arg = ft_split(argv[argc - 1], ' ');
	else
		new_arg = argv;
	array = malloc(lst->a_size * sizeof(int));
	inx = 0;
	while (new_arg[inx])
	{
		if (ft_latoi(new_arg[inx]) > INT_MAX
			|| ft_latoi(new_arg[inx]) < INT_MIN)
			exit_clean(array);
		else
			array[inx] = (int)ft_latoi(new_arg[inx]);
		inx++;
	}
	if (is_string(argv, lst) == 0)
		free_str(new_arg);
	check_double(array, lst->a_size, lst);
	return (array);
}

t_head	*init(char **argv, int argc)
{
	t_head	*lst;
	int		*stack;

	lst = (t_head *)malloc(sizeof(t_head));
	lst->a_size = check_size(argv + 1);
	if (lst->a_size <= 1)
	{
		free(lst);
		exit(0);
	}
	lst->b = NULL;
	lst->b_size = 0;
	lst->psx_b = 0;
	lst->sml_a = 1;
	lst->max_b = 0;
	lst->sml_b = 0;
	stack = fill_stack(argv + 1, lst, argc);
	creat_doublelst(stack, &lst);
	return (lst);
}
