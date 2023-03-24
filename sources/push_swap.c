/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:40:34 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/24 09:28:27 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		error_msg(0);
	validate(argv);
	stack_a = new_stack(&argv[1]);
	stack_b = &((t_stack){0});
	basic_sort(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
}
