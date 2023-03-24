/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:57:09 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/24 09:24:56 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

t_node	*new_node(int data, int index);
t_stack	*new_stack(char *arg[]);
void	add_head_node(t_stack *stack, t_node *node);
void	add_tail_node(t_stack *stack, t_node *node);

void	error_msg(int status);
void	terminate(int status, t_stack *stack_a, t_stack *stack_b);
void	free_stack(t_stack *stack);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);

int		validate(char **arg);

int		stack_len(t_stack *stack);
int		find_max(t_stack *stack);
int		max_index(t_stack *stack);
int		find_duplicate(t_stack *stack);
int		is_sorted(t_stack *stack);
int		biggest_number_binary_bit_count(int max);

void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ab(t_stack *stack_a, t_stack *stack_b);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_ab(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);

void	sort_2(t_stack *stack);
void	sort_3(t_stack *stack);
void	sort_4(t_stack *stack_a, t_stack *stack_b);
void	sort_5(t_stack *stack_a, t_stack *stack_b);
void	basic_sort(t_stack *stack_a, t_stack *stack_b);
void	get_index(t_stack *stack);
void	radix(t_stack *stack_a, t_stack *stack_b);

#endif
