/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:20:07 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/06 19:20:16 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	execute_list(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(line, "sa")))
	{
		swap(NULL, list_a);
		return (0);
	}
	if (!(ft_strcmp(line, "sb")))
	{
		swap(NULL, list_b);
		return (0);
	}
	if (!(ft_strcmp(line, "ss")))
	{
		swap(NULL, list_a);
		swap(NULL, list_b);
		return (0);
	}
	if (execute_list2(line, list_a, list_b) == 0)
		return (0);
	if (execute_list3(line, list_a, list_b) == 0)
		return (0);
	if (execute_list4(line, list_a, list_b) == 0)
		return (0);
	return (1);
}

int	execute_list2(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(line, "pa")))
	{
		if (!*list_b)
			return (1);
		pav2(list_a, list_b);
		return (0);
	}
	if (!(ft_strcmp(line, "pb")))
	{
		if (!*list_a)
			return (1);
		pbv2(list_a, list_b);
		return (0);
	}
	return (1);
}

int	execute_list3(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(line, "ra")))
	{
		rotate(NULL, list_a);
		return (0);
	}
	if (!(ft_strcmp(line, "rb")))
	{
		rotate(NULL, list_b);
		return (0);
	}
	if (!(ft_strcmp(line, "rr")))
	{
		rotate(NULL, list_a);
		rotate(NULL, list_b);
		return (0);
	}
	return (1);
}

int	execute_list4(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(line, "rra")))
	{
		reverse_rotate(NULL, list_a);
		return (0);
	}
	if (!(ft_strcmp(line, "rrb")))
	{
		reverse_rotate(NULL, list_b);
		return (0);
	}	
	if (!(ft_strcmp(line, "rrr")))
	{
		reverse_rotate(NULL, list_a);
		reverse_rotate(NULL, list_b);
		return (0);
	}
	return (1);
}
