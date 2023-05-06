/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:33:18 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/05 20:33:20 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_add_elem(t_list *elem, int val)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->value = val;
		tmp->next = elem;
	}
	return (tmp);
}

void	ft_fill_index(t_list **list_a)
{
	t_list	*first;
	t_list	*cp_a;
	int		i;

	first = *list_a;
	cp_a = *list_a;
	while (*list_a)
	{
		cp_a = first;
		i = 0;
		while (cp_a)
		{
			if ((*list_a)->value > cp_a->value)
				i++;
			if ((*list_a)->index != i)
				(*list_a)->index = i;
			if (!cp_a->next)
				break ;
			cp_a = cp_a->next;
		}
		*list_a = (*list_a)->next;
	}
	*list_a = first;
}
