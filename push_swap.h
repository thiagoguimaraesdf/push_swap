/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:55:55 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/30 14:34:05 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"

typedef struct s_stack {
	int				top;
	unsigned int	capacity;
	int				*array;
}	t_stack;

int		ft_atoi(const char *str);
void	quickSort(int arr[], int low, int high);
void	mySort(t_stack *a, t_stack *b);
void	radixSort(t_stack *a, t_stack *b);
void	convert_numbers(t_stack *a);
void	p(t_stack *a, t_stack *b);
void	s(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *stack);
void	r(t_stack *stack);
t_stack	*createStack(unsigned int capacity);
int		isFull(t_stack *stack);
int		isEmpty(t_stack *stack);
void	push(t_stack *stack, int item);
int		pop(t_stack *stack);
int		peek(t_stack *stack);
void	print_stacks(t_stack *a, t_stack *b);
int		check_stack_a(t_stack *stack);
int		count_greater(t_stack *stack);
int		count_smaller(t_stack *stack);

#endif
