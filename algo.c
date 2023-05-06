/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:32:26 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/05 20:32:28 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_len_3(t_list **list_a)
{
	t_list	*f;
	t_list	*s;
	t_list	*t;

	f = *list_a;
	s = f->next;
	t = s->next;
	if (f->value < s->value && s->value < t->value && s->value < t->value)
		return ;
	else if (f->value < s->value && f->value < t->value && s->value > t->value)
	{
		reverse_rotate("rra\n", list_a);
		swap("sa\n", list_a);
	}
	else if (f->value > s->value && f->value < t->value && s->value < t->value)
		swap("sa\n", list_a);
	else if (f->value < s->value && f->value > t->value && s->value > t->value)
		reverse_rotate("rra\n", list_a);
	else if (f->value > s->value && f->value > t->value && s->value < t->value)
		rotate("ra\n", list_a);
	else if (f->value > s->value && f->value > t->value && s->value > t->value)
	{
		rotate("ra\n", list_a);
		swap("sa\n", list_a);
	}
}

void	ft_four_and_five_elems(t_list **list_a, t_list **list_b)
{
	int	len_list_a;
	int	pos_i_min;
	int	pos_i_max;

	len_list_a = list_len(*list_a);
	pos_i_min = find_min_index(list_a);
	ft_logic_four_five(list_a, list_b, pos_i_min, len_list_a);
	len_list_a = list_len(*list_a);
	pos_i_max = find_max_index(list_a);
	ft_logic_four_five(list_a, list_b, pos_i_max, len_list_a);
	len_list_a = list_len(*list_a);
	if (len_list_a == 2 && (*list_a)->index > (*list_a)->next->index)
		swap("sa\n", list_a);
	else if (len_list_a == 3)
		if_len_3(list_a);
	pa(list_a, list_b);
	rotate("ra\n", list_a);
	pa(list_a, list_b);
}

void	ft_radix(t_list **list_a, t_list **list_b)
{
	t_list	*num;
	int		len;
	int		max_bits;
	int		i;
	int		j;

	len = list_len(*list_a);
	max_bits = 0;
	while ((len - 1) >> max_bits != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < len)
		{
			num = *list_a;
			if (((num->index >> i) & 1) == 1)
				rotate("ra\n", list_a);
			else
				pb(list_a, list_b);
		}
		while (*list_b)
			pa(list_a, list_b);
	}
}
