/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:06:49 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/24 09:09:52 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	t_node	*temp;

	if (stack_len(stack) < 2 || stack->head == NULL || stack->tail == NULL)
		return ;
	temp = stack->head;
	stack->head = stack->head->next;
	if (stack->head)
		stack->head->prev = NULL;
	add_tail_node(stack, temp);
	ft_printf("ra\n");
	return ;
}

void	rotate_b(t_stack *stack)
{
	t_node	*temp;

	if (stack_len(stack) < 2 || stack->head == NULL || stack->tail == NULL)
		return ;
	temp = stack->head;
	stack->head = stack->head->next;
	if (stack->head)
		stack->head->prev = NULL;
	add_tail_node(stack, temp);
	ft_printf("rb\n");
	return ;
}

void	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_len(stack_a) < 2 || stack_a->head == NULL
		|| stack_a->tail == NULL)
		return ;
	temp = stack_a->head;
	stack_a->head = stack_a->head->next;
	if (stack_a->head)
		stack_a->head->prev = NULL;
	add_tail_node(stack_a, temp);
	if (stack_len(stack_b) < 2 || stack_b->head == NULL
		|| stack_b->tail == NULL)
		return ;
	temp = stack_b->head;
	stack_b->head = stack_b->head->next;
	if (stack_b->head)
		stack_b->head->prev = NULL;
	add_tail_node(stack_b, temp);
	ft_printf("rr\n");
	return ;
}
