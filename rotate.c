/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:33:36 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/05 20:33:42 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(char *s, t_list **list)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	last = NULL;
	if (list && *list)
	{
		first = *list;
		second = first->next;
		while ((*list)->next)
			*list = (*list)->next;
		last = *list;
		last->next = first;
		*list = second;
		first->next = NULL;
		ft_putstr(s);
	}
}

void	rr(t_list **list_a, t_list **list_b)
{
	rotate(NULL, list_a);
	rotate(NULL, list_b);
	ft_putstr("rr\n");
}
