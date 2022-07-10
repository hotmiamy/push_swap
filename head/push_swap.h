/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:57:17 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/10 03:48:30 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libft/libft.h"

# define PB 0
# define PA 1
# define RA 2
# define RB 3
# define RR 4
# define RRA 5
# define RRB 6
# define RRR 7
# define SA 8
# define SB 9
# define SS 10
# define A 1
# define B 0
# define BIG 1
# define SMALL 0
# define BACK 1
# define NEXT 0
# define FRT 1
# define LAST 0

typedef enum e_bool
{
	TRUE,
	FALSE
}	t_bool;

typedef struct s_stack
{
	int				content;
	int				inx;
	struct s_stack	*next;
	struct s_stack	*back;
}	t_stack;

typedef struct s_algo
{
	int		pxs_a;
	t_stack	*best_a;
	t_stack	*best_b;
	int		pxs_b;
	int		less_move;
}	t_algo;

typedef struct s_head
{
	int		a_size;
	int		sml_a;
	int		psx_a;
	t_stack	*a;
	t_stack	*b;
	int		b_size;
	int		sml_b;
	int		max_b;
	int		psx_b;
	t_algo	algo;
}	t_head;

void	swap_a(t_head *head_list, t_bool print);
void	swap_b(t_head *head_list, t_bool print);
void	swap_swap(t_head **head_lst);
void	push_a(t_head *head_lst);
void	push_b(t_head *head_lst);
void	rotate_a(t_head *head_lst, t_bool print);
void	rotate_b(t_head *head_lst, t_bool print);
void	rotate_rotate(t_head **head_lst);
void	reverse_rotate_a(t_head *head_lst, t_bool print);
void	reverse_rotate_b(t_head *head_lst, t_bool print);
void	reverse_rotate_reverse_rotate(t_head **head_lst);
void	double_lstadd_front(t_stack **list, t_stack *new);
void	double_lstadd_back(t_stack **list, t_stack *new);
void	normalize(t_stack *lst, int lst_size, t_head *head);
void	sort_stack(t_head *lst);
void	creat_doublelst(int *content, t_head **list);
void	exit_clean(int *stack);
void	psw_exit(void);
void	free_stack(t_head **lst);
void	free_str(char **str);
void	free_lst_exit(t_head **lst);
void	new_posix(t_stack *firt, t_stack *middle, t_stack *last, t_head *head);
void	run_nmoves(int n, int move, t_head *lst);
void	big_sort(t_head *lst);
void	best_a(t_head *lst, t_stack *stk_a);
int		find_big_or_small(t_stack *a_b, t_bool big);
int		number_moves(int moves_a, int moves_b, t_head *lst);
t_bool	is_ordered(t_stack *lst);
t_head	*init(char **argv, int argc);
t_stack	*find_inx(t_stack *inx_addr, int *psx, int inx);
t_stack	*psw_ft_lstlast(t_stack *lst);

#endif