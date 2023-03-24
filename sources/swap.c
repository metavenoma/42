/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:22:47 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/24 09:20:50 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack	*stack)
{
	int	temp;

	if (stack_len(stack) < 2)
		return ;
	temp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = temp;
	ft_printf("sa\n");
	return ;
}

void	swap_b(t_stack	*stack)
{
	int	temp;

	if (stack_len(stack) < 2)
		return ;
	temp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = temp;
	ft_printf("sb\n");
	return ;
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (stack_len(stack_a) < 2 && stack_len(stack_b) < 2)
		return ;
	if (stack_len(stack_a) >= 2)
	{
		temp = stack_a->head->data;
		stack_a->head->data = stack_a->head->next->data;
		stack_a->head->next->data = temp;
	}
	if (stack_len(stack_b) >= 2)
	{
		temp = stack_b->head->data;
		stack_b->head->data = stack_b->head->next->data;
		stack_b->head->next->data = temp;
	}
	ft_printf("ss\n");
	return ;
}
