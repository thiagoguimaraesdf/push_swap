/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:29:02 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/31 15:19:50 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(t_stack *index, int value)
{
	int	i;

	i = 0;
	while (i <= index->top)
	{
		if (index->array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	convert_numbers(t_stack *a)
{
	t_stack	*index;
	int		i;

	index = createStack(a->capacity);
	i = 0;
	while (i <= a->top)
	{
		index->array[i] = a->array[i];
		index->top++;
		i++;
	}
	quickSort(index->array, 0, index->top);
	i = 0;
	while (i <= a->top)
	{
		a->array[i] = get_index(index, a->array[i]);
		i++;
	}
	if (index && index->array)
		free(index->array);
	if (index)
		free(index);
}
