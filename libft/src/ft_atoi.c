/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguimara <tguimara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:34:42 by tguimara          #+#    #+#             */
/*   Updated: 2021/08/30 15:50:06 by tguimara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <limits.h>
#include "../include/libft.h"

static int	ft_check_char(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

static void	ft_check_sign(int *sign, const char *str)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = *sign * (-1);
		str++;
	}
}

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	while (ft_check_char(*str) == 1)
		str++;
	ft_check_sign(&sign, str);
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (!ft_isdigit(*str) && *str != '\0')
		return (INT_MIN);
	if (res > 2147483647L && sign == 1)
		return (-1);
	if (res > 2147483648L && sign == -1)
		return (0);
	return (((int)res * sign));
}
