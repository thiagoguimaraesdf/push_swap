/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:21:13 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/30 13:01:22 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	peek(t_stack *stack)
{
	if (isEmpty(stack))
		return (INT_MIN);
	return (stack->array[stack->top]);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int	capacity;

	capacity = a->capacity;
	ft_printf("a\tb\n");
	while (capacity)
	{
		if (capacity - 1 <= a->top)
			ft_printf("%d\t", a->array[capacity - 1]);
		else
			ft_printf("-\t");
		if (capacity - 1 <= b->top)
			ft_printf("%d\t", b->array[capacity - 1]);
		else
			ft_printf("-\t");
		ft_printf("\n");
		capacity--;
	}
	ft_printf("\n");
}

int	check_stack_a(t_stack *stack)
{
	int	cur_pos;

	cur_pos = stack->top;
	while (cur_pos)
	{
		if (stack->array[cur_pos] > stack->array[cur_pos - 1])
			return (0);
		cur_pos--;
	}
	return (1);
}

int	count_greater(t_stack *stack)
{
	int	cur_pos;
	int	res;

	cur_pos = 1;
	res = 0;
	while (cur_pos <= stack->top)
	{
		if (stack->array[0] < stack->array[cur_pos])
			res++;
		cur_pos++;
	}
	return (res);
}

int	count_smaller(t_stack *stack)
{
	int	cur_pos;
	int	res;

	cur_pos = stack->top - 1;
	res = 0;
	while (cur_pos >= 0)
	{
		if (stack->array[stack->top] > stack->array[cur_pos])
			res++;
		cur_pos--;
	}
	return (res);
}
