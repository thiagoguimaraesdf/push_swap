/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:55:55 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/20 15:15:26 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

/* 
A structure to represent a stack
*/
typedef struct s_stack {
    int top;
    unsigned capacity;
    int* array;
}	t_stack;

int		ft_atoi(const char *str);
void	quickSort(int arr[], int low, int high);

#endif
