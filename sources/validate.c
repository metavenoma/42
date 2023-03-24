/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:12:51 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/24 09:26:53 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_duplicate(t_stack *stack)
{
	t_node	*check;
	t_node	*aux;

	aux = stack->head;
	while (aux->next != NULL)
	{
		check = aux->next;
		while (check->next != NULL)
		{
			if (aux->data == check->data)
				return (0);
			check = check->next;
		}
		if (aux->data == check->data)
			return (0);
		aux = aux->next;
	}
	if (aux->data == aux->prev->data)
		return (0);
	return (1);
}

int	is_sorted(t_stack *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack->head;
	while (temp->next != NULL)
	{
		if (temp->next->data < temp->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	validate(char **arg)
{
	int	i;

	i = 0;
	while (arg[++i])
	{
		if (ft_strlen(arg[1]) > 11)
			error_msg(0);
		if (!ft_isnum(arg[i]))
			error_msg(0);
		if (ft_atoli(arg[i]) > INT_MAX || ft_atoli(arg[i]) < INT_MIN)
			error_msg(0);
	}
	return (1);
}
