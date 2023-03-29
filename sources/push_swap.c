/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:40:34 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/24 16:33:59 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		exit(0);
	validate(&argv[1]);
	stack_a = new_stack(&argv[1]);
	if (is_sorted(stack_a))
		exit(0);
	stack_b = &((t_stack){0});
	basic_sort(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
}
