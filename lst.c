/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:14:19 by mlangloi          #+#    #+#             */
/*   Updated: 2023/04/28 00:06:31 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	*new_list(void)
{
	return (NULL);
}

int	is_empty(t_list list)
{
	if(!list)
		return(0);
	return (1);
}

int	list_len(t_list list)
{
	int len;

	len = 0;
	if (!is_empty(list) == 0)
	{
		while (list)
		{
			++len;
			list = list->next;
		}
	}
	return (len);
}

void	print_list(t_list list)
{
	if (is_empty(list) == 0)
	{
		printf("liste vide\n");
		return ;
	}
	while (list)
	{
		printf("%d\n", list->nb);
		list = list->next;
	}
}

t_list	push_back(t_list list, int x)
{
	listE *elem;
	listE *temp;

	elem = malloc(sizeof(*elem));
	if (elem == NULL)
		return (NULL);
	elem->nb = x;
	elem->next = NULL;
	if (is_empty(list) == 0)
		return elem;
	temp = list;
	while (temp->next)
		temp = temp->next;
	temp->next = elem;
	return (list);
}

t_list push_front(t_list list, int x)
{
	listE *elem;

	elem = malloc(sizeof(*elem));
	if (elem == NULL)
		return (NULL);
	elem->nb = x;
	if (is_empty(list) == 0)
		elem->next = NULL;
	else
		elem->next = list;
	return (elem);
}

t_list	del_back(t_list list)
{
	listE *temp;
	listE *before;

	if (is_empty(list) == 0)
		return new_list();
	if (list->next == NULL)
	{
		free(list);
		list = NULL;
		return (new_list());
	}
	temp = list;
	before = list;
	while(temp->next)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	free(temp);
	temp = NULL;
	return (list);
}

t_list del_front(t_list list)
{
	listE *elem;

	elem = malloc(sizeof(*elem));
	if (elem == NULL)
		return (NULL);
	if (is_empty(list) == 0)
		return (new_list());
	elem = list->next;
	free(list);
	list = NULL;
	return elem;

}

t_list	clear_list(t_list list)
{
	if (is_empty(list) == 0)
		return (new_list());
	while (list)
		list = del_front(list);
	return (list);
}
