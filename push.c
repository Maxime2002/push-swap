/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:32:19 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/05 20:32:22 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*first_b;

	if (!list_b)
		return ;
	first_b = *list_b;
	*list_b = (*list_b)->next;
	first_b->next = *list_a;
	*list_a = first_b;
	ft_putstr("pa\n");
}

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*first_a;

	if (!list_a)
		return ;
	first_a = *list_a;
	*list_a = (*list_a)->next;
	first_a->next = *list_b;
	*list_b = first_a;
	ft_putstr("pb\n");
}
