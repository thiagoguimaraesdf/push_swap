/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:48:25 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/31 15:20:45 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stacks(t_stack *a, t_stack *b)
{
	if (a && a->array)
	{
		free(a->array);
		a->array = NULL;
	}
	if (a)
	{
		free(a);
		a = NULL;
	}
	if (b && b->array)
	{
		free(b->array);
		b->array = NULL;
	}
	if (b)
	{
		free(b);
		b = NULL;
	}
}

static int	verify_duplicates(int capacity, int item)
{
	static int	*duplicates_check;
	int			i;

	if (!duplicates_check)
		duplicates_check = (int *)malloc(sizeof(int) * capacity);
	i = 0;
	while (*(duplicates_check + i))
	{
		if (item == *(duplicates_check + i))
		{
			free(duplicates_check);
			duplicates_check = NULL;
			return (1);
		}
		i++;
	}	
	if (i < capacity)
		*(duplicates_check + i) = item;
	free(duplicates_check);
	duplicates_check = NULL;
	return (0);
}

static int	read_args(int argc, char **argv, t_stack *a)
{
	while (argc > 1)
	{
		if (ft_atoi(*(argv + argc - 1)) == INT_MIN)
		{
			write(2, "Error\n", 7);
			return (-1);
		}
		push(a, ft_atoi(*(argv + argc-- - 1)) + 1);
		if (verify_duplicates(a->capacity, a->array[a->top]))
		{
			write(2, "Error\n", 7);
			return (-1);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		t_numbers;

	if (argc < 2)
		return (-1);
	t_numbers = argc - 1;
	a = createStack(t_numbers);
	b = createStack(t_numbers);
	if (read_args(argc, argv, a) == -1)
		return (-1);
	convert_numbers(a);
	if (t_numbers > 9)
		radixSort(a, b);
	else
		mySort(a, b);
	free_stacks(a, b);
	return (0);
}
