/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:47:55 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/02 18:33:01 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push_swap(t_list *list_a, t_list *list_b)
{

	print_list(*list_a);
	int len;
	len = list_len(*list_a);
	if (len <= 1)
		return ;
	else if (len == 2)
	{
		if ((*list_a)->nb > (*list_a)->next->nb)
			sa(*list_a);
		return ;
	}
	else if (len == 3)
	{
			if ((*list_a)->nb > (*list_a)->next->nb && (*list_a)->nb > (*list_a)->next->next->nb && (*list_a)->next->nb > (*list_a)->next->next->nb)
	{
		sa(*list_a);
		rra(list_a);
	}
	else if ((*list_a)->nb > (*list_a)->next->nb && (*list_a)->nb < (*list_a)->next->next->nb && (*list_a)->next->nb < (*list_a)->next->next->nb)
	{
		sa(*list_a);
	}
	else if ((*list_a)->nb > (*list_a)->next->nb && (*list_a)->nb > (*list_a)->next->next->nb && (*list_a)->next->nb < (*list_a)->next->next->nb)
		ra(list_a);
	else if ((*list_a)->nb < (*list_a)->next->nb && (*list_a)->nb < (*list_a)->next->next->nb && (*list_a)->next->nb > (*list_a)->next->next->nb)
	{
		ra(list_a);
		sa(*list_a);
		rra(list_a);
	}
	else if ((*list_a)->nb < (*list_a)->next->nb && (*list_a)->nb > (*list_a)->next->next->nb && (*list_a)->next->nb > (*list_a)->next->next->nb)
		rra(list_a);
	else if ((*list_a)->nb < (*list_a)->next->nb && (*list_a)->nb > (*list_a)->next->next->nb && (*list_a)->next->nb < (*list_a)->next->next->nb)
	{
		sa(*list_a);
		ra(list_a);
	}
	return ;

	}
	int pivot = median(*list_a, len);
	printf("pivot == %d\n", pivot);
	int push_count = 0;
	while (list_len(*list_a) > 3)
	{
		if ((*list_a)->nb < pivot)
		{
			pb(list_a, list_b);
			push_count++;
		}
		else
		{	
			ra(list_a);
		}
	}
	push_swap(list_a, list_b);
	while(push_count-- > 0)
		pa(list_a, list_b);
	push_count = 0;
	while(*list_a && (*list_a)->nb >= pivot)
	{
		ra(list_a);
		push_count++;
	printf("test\n");
	}
	push_swap(list_a, list_b);
	while (push_count-- > 0)
		rra(list_a);
}



void	if_len_3(t_list *list_a)
{
	if ((*list_a)->nb > (*list_a)->next->nb && (*list_a)->nb > (*list_a)->next->next->nb && (*list_a)->next->nb > (*list_a)->next->next->nb)
	{
		sa(*list_a);
		rra(list_a);
	}
	else if ((*list_a)->nb > (*list_a)->next->nb && (*list_a)->nb < (*list_a)->next->next->nb && (*list_a)->next->nb < (*list_a)->next->next->nb)
	{
		sa(*list_a);
	}
	else if ((*list_a)->nb > (*list_a)->next->nb && (*list_a)->nb > (*list_a)->next->next->nb && (*list_a)->next->nb < (*list_a)->next->next->nb)
		ra(list_a);
	else if ((*list_a)->nb < (*list_a)->next->nb && (*list_a)->nb < (*list_a)->next->next->nb && (*list_a)->next->nb > (*list_a)->next->next->nb)
	{
		ra(list_a);
		sa(*list_a);
		rra(list_a);
	}
	else if ((*list_a)->nb < (*list_a)->next->nb && (*list_a)->nb > (*list_a)->next->next->nb && (*list_a)->next->nb > (*list_a)->next->next->nb)
		rra(list_a);
	else if ((*list_a)->nb < (*list_a)->next->nb && (*list_a)->nb > (*list_a)->next->next->nb && (*list_a)->next->nb < (*list_a)->next->next->nb)
	{
		sa(*list_a);
		ra(list_a);
	}
	return ;
}





/*
int	check_finish(t_list list_a, t_list list_b)
{
	if (list_b)
		return (1);
	while (list_a && list_a->next)
	{
		if (list_a->nb > list_a->next->nb)
			return (1);
		list_a = list_a->next;
	}
	return (0);
}
*/


int	median(t_list lst, int len)
{
	int	val[len];
	int	i;

	i = 0;
	while (lst)
	{
		val[i++] = lst->nb;
		lst = lst->next;
	}
	qsort(val, len, sizeof(int), cmpfunc);
	return (val[len/2]);
}

int cmpfunc(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}


