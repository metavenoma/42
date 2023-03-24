/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 02:42:03 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/24 09:32:54 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_number_binary_bit_count(int max)
{
	int	counter;

	counter = 0;
	if (max < 0)
		return (0);
	while (max != 0)
	{
		counter++;
		max = max >> 1;
	}
	return (counter);
}

void	get_index(t_stack *stack)
{
	int		is_smaller;
	t_node	*current;
	t_node	*temp;

	current = stack->head;
	temp = stack->head;
	while (current)
	{
		is_smaller = 0;
		while (temp)
		{
			if (current->data > temp->data)
				is_smaller++;
			temp = temp->next;
		}
		current->index = is_smaller;
		temp = stack->head;
		current = current->next;
	}
}

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	int	nodes;
	int	len;
	int	i;
	int	bits;

	i = 0;
	get_index(stack_a);
	len = stack_len(stack_a);
	bits = biggest_number_binary_bit_count(find_max(stack_a));
	while (i < bits)
	{
		nodes = 0;
		while (nodes <= len)
		{
			if (((stack_a->head->index >> i) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			nodes++;
		}
		while (stack_b->head)
			push_a(stack_a, stack_b);
		i++;
	}
}
