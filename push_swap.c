/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:48:25 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/19 14:03:49 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

/* 
function to create a stack of given capacity. It initializes size of
stack as 0
*/
t_stack	*createStack(unsigned capacity)
{
    t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return (stack);
}

int isFull(t_stack *stack)
{
    return (stack->top == stack->capacity - 1);
}
 
int isEmpty(t_stack *stack)
{
    return (stack->top == -1);
}

void push(t_stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(t_stack *stack)
{
    if (isEmpty(stack))
        return (INT_MIN);
    return (stack->array[stack->top--]);
}

int peek(t_stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return (stack->array[stack->top]);
}

#include <stdio.h>

void	print_stacks(t_stack *a, t_stack *b)
{
	int capacity;

	capacity = a->capacity;
	printf("a\tb\n");
	while(capacity)
	{
		if (capacity - 1 <= a->top)
			printf("%d\t", a->array[capacity - 1]);
		else
			printf("-\t");
		if (capacity - 1 <= b->top)
			printf("%d\t", b->array[capacity - 1]);
		else
			printf("-\t");
		printf("\n");
		capacity--;
	}
	printf("\n");
}

void	pa(t_stack *a, t_stack *b)
{
	int	item;

	item = pop(b);
	push(a, item);
	printf("pa\n");
	print_stacks(a, b);
}

void	pb(t_stack *a, t_stack *b)
{
	int	item;

	item = pop(a);
	push(b, item);
	printf("pb\n");
	print_stacks(a, b);
}

void	sa(t_stack *stack)
{
	int	temp;

	temp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = temp;
	printf("sa\n");
}

void	sb(t_stack *stack)
{
	int	temp;

	temp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = temp;
	printf("sb\n");
}

void	sort(t_stack *a, t_stack *b)
{
	while (a->array[a->top] > a->array[a->top - 1] && a->top > 0)
	{
		sa(a);
		print_stacks(a, b);
		pb(a, b);
		if ((b->top > 0) && (b->array[b->top] < b->array[b->top - 1]))
		{
			sb(b);
			print_stacks(a, b);
		}
	}

	while (b->top > -1)
	{
		pa(a, b);
		//print_stacks(a, b);		
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	if (argc < 2)
		return (-1);
	a = createStack(argc - 1);
	b = createStack(argc - 1);
	while(argc > 1)
		push(a, ft_atoi(*(argv + argc-- - 1)));
	print_stacks(a, b);
	sort(a, b);
	print_stacks(a, b);


	return (0);

	
}