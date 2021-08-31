/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:48:25 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/31 14:38:24 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			return (1);
		i++;
	}	
	if (i < capacity)
		*(duplicates_check + i) = item;
	return (0);
}

static int	read_args(int argc, char **argv, t_stack *a)
{
	while (argc > 1)
	{
		if (ft_atoi(*(argv + argc - 1)) == INT_MIN)
		{
			ft_printf("Error\n");
			return (-1);
		}
		push(a, ft_atoi(*(argv + argc-- - 1)) + 1);
		if (verify_duplicates(a->capacity, a->array[a->top]))
		{
			ft_printf("Error\n");
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
	return (0);
}
