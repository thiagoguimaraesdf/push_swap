/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:27:25 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/30 16:54:33 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack, char name)
{
	if (count_greater(stack) < count_smaller(stack))
	{
		r(stack);
		ft_printf("r%c\n", name);
	}
	else if (count_greater(stack) > count_smaller(stack))
	{
		rr(stack);
		ft_printf("rr%c\n", name);
	}
}

static void	verify_and_rotate(t_stack *a, t_stack *b)
{
	if (a->array[a->top] > a->array[0])
		rotate(a, 'a');
	if (b->array[a->top] < b->array[0])
		rotate(b, 'b');
}

static void	a_sort(t_stack *a, t_stack *b)
{
	while (a->top > 0)
	{
		verify_and_rotate(a, b);
		if (a->array[a->top] > a->array[a->top - 1])
		{
			if ((b->top > 0) && (b->array[b->top] < b->array[b->top - 1]))
				ss(a, b);
			s(a);
			ft_printf("sa\n");
		}
		verify_and_rotate(a, b);
		if (check_stack_a(a))
			break ;
		p(a, b);
		ft_printf("pb\n");
		verify_and_rotate(a, b);
		if ((b->top > 0) && (b->array[b->top] < b->array[b->top - 1]))
		{
			if (a->array[a->top] > a->array[a->top - 1])
				ss(a, b);
			s(b);
			ft_printf("sb\n");
		}
	}	
}

static void	b_sort(t_stack *a, t_stack *b)
{
	while (b->top > -1)
	{
		if (b->array[b->top] < b->array[b->top - 1] && b->top)
		{
			s(b);
			ft_printf("sb\n");
		}
		p(b, a);
		ft_printf("pa\n");
		if (a->array[a->top] > a->array[a->top - 1])
		{
			s(a);
			ft_printf("sa\n");
		}
	}	
}

void	mySort(t_stack *a, t_stack *b)
{
	while (!check_stack_a(a))
	{
		a_sort(a, b);
		b_sort(a, b);
	}
}
