/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:19:48 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/24 09:13:49 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_b)
		return ;
	temp = stack_b->head;
	stack_b->head = stack_b->head->next;
	if (stack_b->head)
		stack_b->head->prev = NULL;
	add_head_node(stack_a, temp);
	ft_printf("pa\n");
	return ;
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_a)
		return ;
	temp = stack_a->head;
	stack_a->head = stack_a->head->next;
	if (stack_a->head)
		stack_a->head->prev = NULL;
	add_head_node(stack_b, temp);
	ft_printf("pb\n");
	return ;
}
