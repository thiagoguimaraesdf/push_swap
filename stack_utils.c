/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:20:01 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/30 12:59:35 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*createStack(unsigned int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int *)malloc(stack->capacity * sizeof(int));
	return (stack);
}

int	isFull(t_stack *stack)
{
	return (stack->top == (int)stack->capacity - 1);
}

int	isEmpty(t_stack *stack)
{
	return (stack->top == -1);
}

void	push(t_stack *stack, int item)
{
	if (isFull(stack))
		return ;
	stack->array[++stack->top] = item;
}

int	pop(t_stack *stack)
{
	if (isEmpty(stack))
		return (INT_MIN);
	return (stack->array[stack->top--]);
}
