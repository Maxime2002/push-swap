/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:45:06 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/06 19:07:01 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pav2(t_list **list_a, t_list **list_b)
{
	t_list	*first_b;

	if (!list_b)
		return ;
	first_b = *list_b;
	*list_b = (*list_b)->next;
	first_b->next = *list_a;
	*list_a = first_b;
}

void	pbv2(t_list **list_a, t_list **list_b)
{
	t_list	*first_a;

	if (!list_a)
		return ;
	first_a = *list_a;
	*list_a = (*list_a)->next;
	first_a->next = *list_b;
	*list_b = first_a;
}

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
