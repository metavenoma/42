/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:30:42 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/24 09:12:49 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int		counter;
	t_node	*temp;

	temp = stack->head;
	if (temp == NULL)
		return (0);
	counter = 1;
	while (stack->head->next != NULL)
	{
		counter++;
		stack->head = stack->head->next;
	}
	stack->head = temp;
	temp = NULL;
	return (counter);
}

int	find_max(t_stack *stack)
{
	t_node	*temp;
	int		max;

	max = INT_MIN;
	temp = stack->head;
	if (temp == NULL)
		return (0);
	while (temp->next != NULL)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	if (temp->data > max)
		max = temp->data;
	return (max);
}

int	max_index(t_stack *stack)
{
	t_node	*temp;
	int		max;
	int		i;

	i = 0;
	max = INT_MIN;
	temp = stack->head;
	while (temp->next != NULL)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	if (temp->data > max)
		max = temp->data;
	temp = stack->head;
	while (temp->next != NULL)
	{
		if (max == temp->data)
			return (i);
		temp = temp->next;
		i++;
	}
	return (i);
}
