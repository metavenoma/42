/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:43:32 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/24 09:08:08 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack)
{
	t_node	*temp;

	if (stack_len(stack) < 2 || stack->head == NULL || stack->tail == NULL)
		return ;
	temp = stack->tail;
	stack->tail = stack->tail->prev;
	if (stack->head)
		stack->tail->next = NULL;
	add_head_node(stack, temp);
	ft_printf("rra\n");
	return ;
}

void	reverse_rotate_b(t_stack *stack)
{
	t_node	*temp;

	if (stack_len(stack) < 2 || stack->head == NULL || stack->tail == NULL)
		return ;
	temp = stack->tail;
	stack->tail = stack->tail->prev;
	if (stack->head)
		stack->tail->next = NULL;
	add_head_node(stack, temp);
	ft_printf("rrb\n");
	return ;
}

void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_len(stack_a) < 2 || stack_a->head == NULL
		|| stack_a->tail == NULL)
		return ;
	temp = stack_a->tail;
	stack_a->tail = stack_a->tail->prev;
	if (stack_a->head)
		stack_a->tail->next = NULL;
	add_head_node(stack_a, temp);
	if (stack_len(stack_b) < 2 || stack_b->head == NULL
		|| stack_b->tail == NULL)
		return ;
	temp = stack_b->tail;
	stack_b->tail = stack_b->tail->prev;
	if (stack_b->head)
		stack_b->tail->next = NULL;
	add_head_node(stack_b, temp);
	ft_printf("rrr\n");
	return ;
}
