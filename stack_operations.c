/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:23:39 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/30 14:56:36 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p(t_stack *a, t_stack *b)
{
	int	item;

	item = pop(a);
	push(b, item);
}

void	s(t_stack *stack)
{
	int	temp;

	temp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = temp;
}

void	ss(t_stack *a, t_stack *b)
{
	s(a);
	s(b);
	ft_printf("ss\n");
}

void	rr(t_stack *stack)
{
	int	cur_pos;
	int	last;
	int	cur;

	cur_pos = stack->top;
	while (cur_pos > -1)
	{
		if (cur_pos == stack->top)
		{
			last = stack->array[cur_pos];
			stack->array[cur_pos] = stack->array[0];
		}
		else
		{
			cur = stack->array[cur_pos];
			stack->array[cur_pos] = last;
			last = cur;
		}
		cur_pos--;
	}
}

void	r(t_stack *stack)
{
	int	cur_pos;
	int	last;
	int	cur;

	cur_pos = 0;
	while (cur_pos <= stack->top)
	{
		if (cur_pos == 0)
		{
			last = stack->array[cur_pos];
			stack->array[cur_pos] = stack->array[stack->top];
		}
		else
		{
			cur = stack->array[cur_pos];
			stack->array[cur_pos] = last;
			last = cur;
		}
		cur_pos++;
	}
}
