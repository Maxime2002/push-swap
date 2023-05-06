/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:33:31 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/05 20:33:32 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(char *s, t_list **list)
{
	t_list	*first;
	t_list	*b_last;
	t_list	*last;

	b_last = NULL;
	if (list && *list)
	{
		first = *list;
		while ((*list)->next)
		{
			if (!(*list)->next->next && !b_last)
				b_last = *list;
			*list = (*list)->next;
		}
		last = *list;
		*list = last;
		last->next = first;
		b_last->next = NULL;
		ft_putstr(s);
	}
}

void	rrr(t_list **list_a, t_list **list_b)
{
	reverse_rotate(NULL, list_a);
	reverse_rotate(NULL, list_b);
	ft_putstr("rrr\n");
}
