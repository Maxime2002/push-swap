/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:47:16 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/06 19:06:02 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

t_list	*ft_add_elem(t_list *elem, int val)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->nb = val;
		tmp->next = elem;
	}
	return (tmp);
}

void	ft_error(t_list *list_a, t_list *list_b, int res, char *error)
{
	if (res < 0)
	{
		ft_free_list(list_a, list_b);
		write(2, error, ft_strlen(error));
		exit(EXIT_FAILURE);
	}
}
