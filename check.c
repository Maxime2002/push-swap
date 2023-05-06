/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:32:13 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/05 20:32:15 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_double(t_list *elem)
{
	t_list	*tmp;

	if (elem)
	{
		while (elem->next)
		{
			tmp = elem->next;
			while (tmp)
			{
				if (elem->nb == tmp->nb)
					return (-1);
				tmp = tmp->next;
			}
			elem = elem->next;
		}
	}
	return (0);
}

int	check_finish(t_list *list_a)
{
	t_list	*tmp;

	if (list_a)
	{
		while ((list_a)->next)
		{
			tmp = (list_a)->next;
			while (tmp)
			{
				if ((list_a)->nb > tmp->nb)
					return (-1);
				tmp = tmp->next;
			}
			list_a = (list_a)->next;
		}
	}
	else
		return (-1);
	return (0);
}
