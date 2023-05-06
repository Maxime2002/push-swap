/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:33:05 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/05 20:33:07 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		ft_if_is_two_args(argc, argv, &list_a);
		ft_sort(&list_a, &list_b);
	}
	else
	{
		while (--argc >= 1)
			list_a = ft_add_elem(list_a, ft_atoi(argv[argc], list_a));
		ft_error(list_a, list_b, ft_is_double(list_a), "Error\n");
		ft_sort(&list_a, &list_b);
	}
	ft_free_list(list_a, NULL);
	return (0);
}
