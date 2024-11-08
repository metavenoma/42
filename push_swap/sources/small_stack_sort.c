/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:58:17 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/24 15:52:32 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack)
{
	if (stack->head->data > stack->head->next->data)
		swap_a(stack);
}

void	sort_3(t_stack *stack)
{
	int	max;

	if (is_sorted(stack))
		return ;
	max = max_index(stack);
	if (max == 0)
		rotate_a(stack);
	else if (max == 1)
		reverse_rotate_a(stack);
	if (stack->head->data > stack->head->next->data)
		swap_a(stack);
}

void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	max;

	if (is_sorted(stack_a))
		return ;
	max = max_index(stack_a);
	if (max == 1)
		swap_a(stack_a);
	else if (max == 3)
		reverse_rotate_a(stack_a);
	else if (max == 2)
	{
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
	rotate_a(stack_a);
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	max;

	max = max_index(stack_a);
	if (max == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (max == 1)
		swap_a(stack_a);
	else if (max == 4)
		reverse_rotate_a(stack_a);
	else if (max == 3)
	{
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	push_a(stack_a, stack_b);
	rotate_a(stack_a);
}

void	basic_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!find_duplicate(stack_a))
		terminate(1, stack_a, stack_b);
	if (stack_len(stack_a) < 2)
		return ;
	else if (stack_len(stack_a) == 2)
		sort_2(stack_a);
	else if (stack_len(stack_a) == 3)
		sort_3(stack_a);
	else if (stack_len(stack_a) == 4)
		sort_4(stack_a, stack_b);
	else if (stack_len(stack_a) == 5)
		sort_5(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}
