/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:32:39 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/31 11:21:33 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	b_to_a(t_stack *a, t_stack *b)
{
	while (!isEmpty(b))
	{
		p(b, a);
		ft_printf("pa\n");
	}	
}

static void	radix_operations(int i, int num, t_stack *a, t_stack *b)
{
	if (((num >> i) & 1) == 1)
	{
		r(a);
		ft_printf("ra\n");
	}
	else
	{
		p(a, b);
		ft_printf("pb\n");
	}
}

static void	radix_helper(int max_bits, int size, t_stack *a, t_stack *b)
{
	int	num;
	int	i;
	int	j;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = a->array[a->top];
			radix_operations(i, num, a, b);
			j++;
		}
		b_to_a(a, b);
		i++;
	}
}

void	radixSort(t_stack *a, t_stack *b)
{
	int	size;
	int	max_num;
	int	max_bits;

	size = a->capacity;
	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	radix_helper(max_bits, size, a, b);
}
