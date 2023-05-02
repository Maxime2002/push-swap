/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:18:32 by mlangloi          #+#    #+#             */
/*   Updated: 2023/04/28 01:48:15 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sa(t_list list_a)
{
	int	temp;

	if (!list_a || !list_a->next)
		return ;
	temp = list_a->nb;
	list_a->nb = list_a->next->nb;
	list_a->next->nb = temp;
	ft_putstr("sa\n");
}

void	sb(t_list list_b)
{
	int	temp;

	if (!list_b || !list_b->next)
		return ;
	temp = list_b->nb;
	list_b->nb = list_b->next->nb;
	list_b->next->nb = temp;
	ft_putstr("sb\n");
}

void	ss(t_list list_a, t_list list_b)
{
	int	temp;

	if (!list_a || !list_a->next || !list_b || !list_b->next)
		return ;
	temp = list_a->nb;
	list_a->nb = list_a->next->nb;
	list_a->next->nb = temp;
	temp = list_b->nb;
	list_b->nb = list_b->next->nb;
	list_b->next->nb = temp;
	ft_putstr("ss\n");
}

void	pa(t_list *list_a, t_list *list_b)
{
	int	temp;

	if (!list_b)
		return ;
	temp = (*list_b)->nb;
	*list_b = del_front(*list_b);
	*list_a = push_front(*list_a, temp);
	ft_putstr("pa\n");
}

void	pb(t_list *list_a, t_list *list_b)
{
	int	temp;

	if (!list_a)
		return ;
	temp = (*list_a)->nb;
	*list_a = del_front(*list_a);
	*list_b = push_front(*list_b, temp);
	ft_putstr("pb\n");
}

void ra(t_list *list_a)
{
	int temp;

	if (!list_a || !(*list_a)->next)
		return ;
	temp = (*list_a)->nb;
	*list_a = del_front(*list_a);
	*list_a = push_back(*list_a, temp);
	ft_putstr("ra\n");
}

void rb(t_list *list_b)
{
	int temp;

	if (!list_b || !(*list_b)->next)
		return ;
	temp = (*list_b)->nb;
	*list_b = del_front(*list_b);
	*list_b = push_back(*list_b, temp);
	ft_putstr("rb\n");
}

void rr(t_list *list_a, t_list *list_b)
{
	int temp;

	if (!list_a || !(*list_a)->next || !list_b || !(*list_b)->next)
		return ;	
	temp = (*list_a)->nb;
	*list_a = del_front(*list_a);
	*list_a = push_back(*list_a, temp);
	temp = (*list_b)->nb;
	*list_b = del_front(*list_b);
	*list_b = push_back(*list_b, temp);
	ft_putstr("rr\n");
}

void	rra(t_list *list_a)
{
	t_list	new;
	int	temp;

	if (!list_a || !(*list_a)->next)
		return ;
	new = *list_a;
	while (new->next)
		new = new->next;
	temp = new->nb;
    	*list_a = del_back(*list_a);
	*list_a = push_front(*list_a, temp);
	ft_putstr("rra\n");
}


void	rrb(t_list *list_b)
{
	t_list	new;
	int	temp;

	if (!list_b || !(*list_b)->next)
		return ;
	new = *list_b;
	while (new->next)
		new = new->next;
	temp = new->nb;
    	*list_b = del_back(*list_b);
	*list_b = push_front(*list_b, temp);
	ft_putstr("rrb\n");
}

void	rrr(t_list *list_a, t_list *list_b)
{
	t_list	new;
	int	temp;

	if (!list_a || !(*list_a)->next || !list_b || !(*list_b)->next)
		return ;
	new = *list_a;
	while (new->next)
		new = new->next;
	temp = new->nb;
    	*list_a = del_back(*list_a);
	*list_a = push_front(*list_a, temp);

	new = *list_b;
	while (new->next)
		new = new->next;
	temp = new->nb;
    	*list_b = del_back(*list_b);
	*list_b = push_front(*list_b, temp);
	ft_putstr("rrr\n");
}
