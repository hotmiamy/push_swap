/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:16:21 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/16 02:49:07 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

t_stack	*double_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->inx = 0;
	new->next = NULL;
	new->back = NULL;
	return (new);
}

void	double_lstadd_back(t_stack **list, t_stack *new)
{
	t_stack	*head;

	if ((*list) == NULL)
		(*list) = new;
	else
	{
		head = *list;
		while ((*list)->next)
			*list = (*list)->next;
		new->back = *list;
		(*list)->next = new;
		*list = head;
	}
}

void	double_lstadd_front(t_stack **list, t_stack *new)
{
	if (*list == NULL)
	{
		*list = new;
		new->next = NULL;
	}
	else
	{
		new->next = *list;
		new->back = NULL;
		(*list)->back = new;
		*list = new;
	}
}

t_stack	*psw_ft_lstlast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	creat_doublelst(int *content, t_head **list)
{
	int			inx;

	inx = 0;
	(*list)->a = double_lstnew(content[inx++]);
	while (inx < (*list)->a_size)
		double_lstadd_back(&(*list)->a, double_lstnew(content[inx++]));
	free(content);
}
