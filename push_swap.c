/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:48:25 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/20 16:00:53 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

/* 
function to create a stack of given capacity. It initializes size of
stack as 0
*/
int count = 0;

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
	
	count++;
	
	item = pop(b);
	push(a, item);
	printf("pa\n");
	//print_stacks(a, b);
}

void	pb(t_stack *a, t_stack *b)
{
	int	item;
	
	count++;
	
	item = pop(a);
	push(b, item);
	printf("pb\n");
	//print_stacks(a, b);
}

void	sa(t_stack *stack)
{
	int	temp;
	
	count++;
	
	temp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = temp;
	printf("sa\n");
}

void	sb(t_stack *stack)
{
	int	temp;
	
	count++;
	
	temp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = temp;
	printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	count++;
	printf("ss\n");		
}

void	rra(t_stack *a)
{
	int	cur_pos;
	int last;
	int cur;

	count++;

	cur_pos = a->top;
	while(cur_pos > -1)
	{
		if (cur_pos == a->top)
		{
			last = a->array[cur_pos];
			a->array[cur_pos] = a->array[0];
		}
		else
		{
			cur = a->array[cur_pos]; 
			a->array[cur_pos] = last;
			last = cur;
		}
		cur_pos--;
	}
	printf("rra\n");
}

void	rrb(t_stack *b)
{
	int	cur_pos;
	int last;
	int cur;

	count++;

	cur_pos = b->top;
	while(cur_pos > -1)
	{
		if (cur_pos == b->top)
		{
			last = b->array[cur_pos];
			b->array[cur_pos] = b->array[0];
		}
		else
		{
			cur = b->array[cur_pos]; 
			b->array[cur_pos] = last;
			last = cur;
		}
		cur_pos--;
	}
	printf("rrb\n");	
}

void	ra(t_stack *a)
{
	int	cur_pos;
	int last;
	int cur;

	count++;

	cur_pos = 0;
	while (cur_pos <= a->top)
	{
		if (cur_pos == 0)
		{
			last = a->array[cur_pos];
			a->array[cur_pos] = a->array[a->top];	
		}
		else
		{
			cur = a->array[cur_pos]; 
			a->array[cur_pos] = last;
			last = cur;
		}
		cur_pos++;		
	}
	printf("ra\n");	
}

void	rb(t_stack *b)
{
	int	cur_pos;
	int last;
	int cur;

	count++;

	cur_pos = 0;
	while(cur_pos <= b->top)
	{
		if (cur_pos == 0)
		{
			last = b->array[cur_pos];
			b->array[cur_pos] = b->array[b->top];	

		}
		else
		{
			cur = b->array[cur_pos]; 
			b->array[cur_pos] = last;
			last = cur;
		}
		cur_pos++;
	}
	printf("rb\n");		
}


int	check_stack_a(t_stack *stack)
{
	int cur_pos;

	cur_pos = stack->top;
	while(cur_pos)
	{
		if (stack->array[cur_pos] > stack->array[cur_pos - 1])
			return (0);
		cur_pos--;
	}
	return (1);
}

int	count_greater(t_stack *stack)
{
	int cur_pos;
	int res;
	
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
	int cur_pos;
	int res;
	
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

void	verify_and_rotate(t_stack *a, t_stack *b)
{
	if (a->array[a->top] > a->array[0])
	{
		if (count_greater(a) > count_smaller(a))
			ra(a);
		else if (count_greater(a) == count_smaller(a))
		{
			if (a->capacity < 5)
				ra(a);
			else
				rra(a);
		}
		else
			rra(a);
		//print_stacks(a, b);
	}

	if (b->array[a->top] < b->array[0])
	{
		if (count_greater(b) > count_smaller(b))
			rb(b);
		else if (count_greater(b) == count_smaller(b))
		{
			if (b->capacity < 5)
				rb(b);
			else
				rrb(b);
		}
		else
			rrb(b);
	}
}

void	my_sort(t_stack *a, t_stack *b)
{
	/*
	
	*/
	while (!check_stack_a(a))
	{
		/*
			Swap to order and push items from 'a' to 'b'.
			When a item gets to 'b', swap if necessary
			Stop when stack 'a' is ordered
			TO DO:
			- sb and sa can come in some op if both conditions are satisfied
		
		*/
		while (a->top > 0)
		{
			verify_and_rotate(a, b);
			if (a->array[a->top] > a->array[a->top - 1])
			{
				if ((b->top > 0) && (b->array[b->top] < b->array[b->top - 1]))
					ss(a, b);
				sa(a);
				//print_stacks(a, b);
			}
			if (check_stack_a(a))
				break ;
			pb(a, b);
			verify_and_rotate(a, b);
			if ((b->top > 0) && (b->array[b->top] < b->array[b->top - 1]))
			{
				if (a->array[a->top] > a->array[a->top - 1])
					ss(a, b);
				sb(b);
				//print_stacks(a, b);
			}
		}
		/*
			Swap to order and push items from 'b' to 'a'.
			When 'a' item gets to 'a', swap if necessary
		*/
		while (b->top > -1)
		{
			if (b->array[b->top] < b->array[b->top - 1] && b->top)
				sb(b);
			pa(a, b);
			if (a->array[a->top] > a->array[a->top - 1])
			{
				sa(a);	
				//print_stacks(a, b);		
			}
		}		
	}
}


void	radix_sort(t_stack *a, t_stack *b)
{
	int size;
	int max_num; // the biggest number in a is stack_size - 1
	int max_bits; // how many bits for max_num 

	size = a->top;
	max_num = a->capacity - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0) 
		++max_bits;
	for (int i = 0 ; i < max_bits ; ++i) // repeat for max_bits times
	{
		for(int j = 0 ; j < size ; ++j)
		{
			int num = a->array[a->top]; // top number of A
			if ((num >> i)&1 == 1) 
				ra(a); 
			// if the (i + 1)-th bit is 1, leave in stack a
			else 
				pb(a, b);
			// otherwise push to stack b
		}
		// put into boxes done
		while (!isEmpty(b)) 
			pa(a, b); // while stack b is not empty, do pa
		// connect numbers done
	}
}

int verify_duplicates(int capacity, int item)
{
	static int 	*duplicates_check;
	int 		i;
	
	if (!duplicates_check)
		duplicates_check = (int *)malloc(sizeof(int) * capacity);
	i = 0;
	while(*(duplicates_check + i))
	{
		if (item == *(duplicates_check + i))		
			return (1);
		i++;
	}	
	if (i < capacity)
		*(duplicates_check + i) = item;
	return (0);
}

int 	get_index(t_stack *index, int value)
{
	int	i;

	i = 0;
	while (i <= index->top)
	{
		// printf("i:%d\tindex[i]:%d\tvalue:%d\n", i, index->array[i], value);		
		if (index->array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	convert_numbers(t_stack *a)
{
	t_stack	*index;
	int 	i;

	index = createStack(a->capacity);
	i = 0;
	while (i <= a->top)
	{
		index->array[i] = a->array[i];
		index->top++;
		i++;
	}
	quickSort(index->array, 0 , index->top);
	i = 0;
	while (i <= a->top)
	{
		// printf("ai:%d\n", a->array[i]);
		a->array[i] = get_index(index, a->array[i]);
		i++;
	}
}


int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int 	error;


	error = 0;
	
	if (argc < 2)
		return (-1);
	a = createStack(argc - 1);
	b = createStack(argc - 1);
	/*
		verify numbers and push to stack 'a'
	*/
	while(argc > 1)
	{
		if (ft_atoi(*(argv + argc - 1)) == INT_MIN)
		{
			printf("Error\n");
			return (-1);	
		}
		push(a, ft_atoi(*(argv + argc-- - 1)));
		if (verify_duplicates(a->capacity, a->array[a->top]))
		{
			printf("Error\n");
			return (-1);
		}
	}
	/*
		convert number to positive
	*/
	convert_numbers(a);
	// print_stacks(a, b);
	radix_sort(a, b);
	// print_stacks(a, b);
	// printf("count:%d\n", count);
	
	return (0);

	
}