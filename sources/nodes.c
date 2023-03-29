/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:08:20 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/24 16:22:22 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_head_node(t_stack *stack, t_node *node)
{
	t_node	*temp;

	if (stack->head == 0)
	{
		stack->head = node;
		stack->head->prev = NULL;
		stack->head->next = NULL;
		return ;
	}
	else
	{	
		temp = stack->head;
		temp->prev = node;
		node->next = temp;
		node->prev = NULL;
		stack->head = node;
	}
	return ;
}

void	add_tail_node(t_stack *stack, t_node *node)
{
	t_node	*temp;

	if (stack->tail == 0)
	{
		stack->tail = node;
		stack->tail->next = NULL;
		stack->tail->prev = NULL;
	}
	else
	{
		temp = stack->tail;
		temp->next = node;
		node->prev = temp;
		node->next = NULL;
		stack->tail = node;
	}
	return ;
}

t_node	*new_node(long long data, int index)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*new_stack(char *arg[])
{
	int		i;
	t_stack	*stack;
	t_node	*head;
	t_node	*temp;
	t_node	*node;

	i = 0;
	stack = (t_stack *)malloc(sizeof(t_stack));
	head = new_node(ft_atoll(arg[i]), 0);
	node = head;
	while (arg[++i])
	{
		node->next = new_node(ft_atoll(arg[i]), 0);
		temp = node;
		node = node->next;
		node->prev = temp;
	}
	stack->head = head;
	stack->tail = node;
	get_index(stack);
	return (stack);
}
