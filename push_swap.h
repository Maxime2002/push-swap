/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:33:24 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/05 22:28:20 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				nb;
	int				index;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(char *s);
int		ft_atoi(char *str, t_list *elem);
char	**ft_split(char const *s, char c);
void	ft_putstr(char *s);

t_list	*ft_add_elem(t_list *elem, int val);
void	ft_fill_index(t_list **list_a);

int		ft_is_double(t_list *elem);
int		check_finish(t_list *list_a);

void	pa(t_list **list_a, t_list **list_b);
void	pb(t_list **list_a, t_list **list_b);
void	swap(char *s, t_list **list);
void	ss(t_list **list_a, t_list **list_b);
void	rotate(char *s, t_list **list);
void	rr(t_list **list_a, t_list **list_b);

void	reverse_rotate(char *s, t_list **list);
void	rrr(t_list **list_a, t_list **list_b);

void	if_len_3(t_list **list_a);
void	ft_four_and_five_elems(t_list **list_a, t_list **list_b);
void	ft_radix(t_list **list_a, t_list **list_b);

void	ft_if_is_two_args(int argc, char **argv, t_list **list);
void	ft_sort(t_list **list_a, t_list **list_b);
void	ft_logic_four_five(t_list **s_a, t_list **s_b, int pos, int len_s_a);

void	ft_free_list(t_list *list_a, t_list *list_b);
void	ft_error(t_list *list_a, t_list *list_b, int res, char *error);
int		list_len(t_list *list);
int		find_min_index(t_list **list);
int		find_max_index(t_list **list);

#endif
