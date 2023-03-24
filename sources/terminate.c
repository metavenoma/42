/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 08:36:32 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/24 09:24:59 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	terminate(int status, t_stack *stack_a, t_stack *stack_b)
{
	free_stacks(stack_a, stack_b);
	ft_printf("Error\n");
	exit(status);
}

void	error_msg(int status)
{
	ft_printf("Error\n");
	exit(status);
}

void	free_stack(t_stack *stack)
{
	t_node	*aux;

	if (stack == NULL)
		return ;
	while (stack->head->next != NULL)
	{
		aux = stack->head->next;
		free(stack->head);
		stack->head = aux;
	}
	free(stack->head);
	if (stack)
		free (stack);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->head)
		free_stack(stack_a);
	if (stack_b->head)
		free_stack(stack_b);
}
