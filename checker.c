/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:38:42 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/06 19:55:02 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_result(t_list **list_a, t_list **list_b)
{
	if (check_finish(*list_a) == 0 && !*list_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	if (*list_a || *list_b)
		ft_free_list(*list_a, *list_b);
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;

	if (ac < 2)
		return (0);
	list_a = NULL;
	list_b = NULL;
	while (--ac >= 1)
		list_a = ft_add_elem(list_a, ft_atoi(av[ac], list_a));
	if (ft_traitement(list_a, list_b) == 0)
		return (0);
	ft_result(&list_a, &list_b);
	return (0);
}

int	ft_traitement(t_list *list_a, t_list *list_b)
{
	char	*line;

	if (ft_is_double(list_a) == -1)
	{
		ft_error(list_a, list_b, -1, "Error\n");
		return (0);
	}
	line = get_next_line(0);
	while (line != NULL)
	{
		if (execute_list(line, &list_a, &list_b) == 1)
		{
			ft_error(list_a, list_b, -1, "Error\n");
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}
