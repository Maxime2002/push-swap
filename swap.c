/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:33:50 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/05 20:33:52 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *s, t_list **list)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (list && *list && (*list)->next)
	{
		first = *list;
		second = first->next;
		*list = second;
		if (second->next)
			third = second->next;
		else
			third = NULL;
		first->next = third;
		second->next = first;
		ft_putstr(s);
	}
}

void	ss(t_list **list_a, t_list **list_b)
{
	swap(NULL, list_a);
	swap(NULL, list_b);
	ft_putstr("ss\n");
}
