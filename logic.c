/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:32:59 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/05 20:33:00 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_if_is_two_args(int argc, char **argv, t_list **list)
{
	int		i;
	char	**tab;

	tab = NULL;
	if (argc == 2)
	{
		i = 0;
		tab = ft_split(argv[1], ' ');
		if (!tab || !tab[i])
			ft_error(NULL, NULL, -1, "Error\n");
		while (tab[i])
			i++;
		while (--i >= 0)
			*list = ft_add_elem(*list, ft_atoi(tab[i], *list));
		i = -1;
		while (tab[++i])
			free(tab[i]);
		free(tab[i]);
		free(tab);
		ft_error(*list, NULL, ft_is_double(*list), "Error\n");
	}
}

void	ft_sort(t_list **list_a, t_list **list_b)
{
	t_list	*cp_a;
	int		nb_elem;

	nb_elem = 0;
	cp_a = *list_a;
	ft_fill_index(list_a);
	if (check_finish(*list_a) == 0)
	{
		ft_free_list(*list_a, NULL);
		exit(EXIT_SUCCESS);
	}
	while (cp_a)
	{
		cp_a = cp_a->next;
		nb_elem++;
	}
	if (nb_elem == 2 && (*list_a)->value > (*list_a)->next->value)
		swap("sa\n", list_a);
	else if (nb_elem == 3)
		if_len_3(list_a);
	else if (nb_elem > 3 && nb_elem < 6)
		ft_four_and_five_elems(list_a, list_b);
	else if (nb_elem > 5)
		ft_radix(list_a, list_b);
}

void	ft_logic_four_five(t_list **s_a, t_list **s_b, int pos, int len_s_a)
{
	int	i;

	i = -1;
	if (pos <= len_s_a / 2)
		while (++i < pos)
			rotate("ra\n", s_a);
	else if (pos > len_s_a / 2)
		while (++i < len_s_a - pos)
			reverse_rotate("rra\n", s_a);
	pb(s_a, s_b);
}
