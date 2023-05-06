/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:32:47 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/05 20:32:49 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_atoi(char *str, t_list	*elem)
{
	size_t		i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
		if (result * sign < -2147483648 || result * sign > 2147483647)
			ft_error(elem, NULL, -1, "Error\n");
	}
	if (str[i] || (sign == -1 && i == 1) || i == 0 || str[0] == '+')
		ft_error(elem, NULL, -1, "Error\n");
	return (result * sign);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}
