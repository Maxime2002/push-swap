/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:33:59 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/05 20:34:01 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(t_list *list_a, t_list *list_b)
{
	t_list	*tmp;

	while (list_a)
	{
		tmp = list_a;
		list_a = tmp->next;
		free(tmp);
	}
	while (list_b)
	{
		tmp = list_b;
		list_b = tmp->next;
		free(tmp);
	}
}

void	ft_error(t_list *list_a, t_list *list_b, int res, char *error)
{
	if (res < 0)
	{
		ft_free_list(list_a, list_b);
		write(2, error, ft_strlen(error));
		exit(EXIT_FAILURE);
	}
}

int	list_len(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int	find_min_index(t_list **list)
{
	t_list	*first;
	int		count;

	first = *list;
	count = 0;
	while (*list)
	{
		if ((*list)->index == 0)
			break ;
		count++;
		*list = (*list)->next;
	}
	*list = first;
	return (count);
}

int	find_max_index(t_list **list)
{
	t_list	*first;
	int		max_index;
	int		count;

	first = *list;
	max_index = list_len(*list);
	count = 0;
	while (*list)
	{
		if ((*list)->index == max_index)
			break ;
		count++;
		*list = (*list)->next;
	}
	*list = first;
	return (count);
}
