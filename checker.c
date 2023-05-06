/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:38:42 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/05 22:50:02 by mlangloi         ###   ########.fr       */
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

void	ft_result(t_list **list_a, t_list **list_b)
{
	if (check_finish(*list_a) == 0 && !*list_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	if (*list_a || *list_b)
		ft_free_list(*list_a, *list_b);
}

int main(int ac, char **av)
{
	t_list	*list_a; 
	t_list	*list_b; 
	char	*line;

	if  (ac < 2)
		return (0);
	list_a = NULL;
	list_b = NULL; 
	while (--ac >= 1)
		list_a = ft_add_elem(list_a, ft_atoi(av[ac], list_a));
	if (ft_is_double(list_a) == -1)
	{
		ft_error(list_a, list_b, -1, "Error\n");
		return (0);
	}
	while ((line = get_next_line(0)) != NULL)
	{
		if (execute_list(line, &list_a, &list_b) == 1) 
		{
			ft_error(list_a, list_b, -1, "Error\n");
			return (0);
		}
		free(line);
	}
	ft_result(&list_a, &list_b);
	return (0);
}
