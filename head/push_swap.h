/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:57:17 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/09 04:09:38 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*back;
}	t_stack;

typedef struct s_head
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_head;

void	swap_a(t_head *head_list);
void	swap_b(t_head *head_list);
void	swap_swap(t_head **head_lst);
void	push_a(t_head *head_lst);
void	push_b(t_head *head_lst);
void	rotate_a(t_head *head_lst);
void	rotate_b(t_head *head_lst);
void	rotate_rotate(t_head **head_lst);
void	reverse_rotate_a(t_head *head_lst);
void	reverse_rotate_b(t_head *head_lst);
void	reverse_rotate_reverse_rotate(t_head **head_lst);
void	double_lstadd_front(t_stack **list, t_stack *new);
void	double_lstadd_back(t_stack **list, t_stack *new);
t_head	*creat_doublelst(int *content);
t_stack	*psw_ft_lstlast(t_stack *lst);

#endif