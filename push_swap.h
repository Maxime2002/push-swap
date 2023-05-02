/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:03:21 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/02 18:27:33 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct s_list
{
	int nb;
	struct s_list	*next;
}	listE, *t_list;

void	sa(t_list list_a);
void	sb(t_list list_b);
void	ss(t_list list_a, t_list list_b);
void	pa(t_list *list_a, t_list *list_b);
void	pb(t_list *list_a, t_list *list_b);
void	ra(t_list *list_a);
void	rb(t_list *list_b);
void	rr(t_list *list_a, t_list *list_b);
void	rra(t_list *list_a);
void	rrb(t_list *list_b);
void	rrr(t_list *list_a, t_list *list_b);

//int	check_finish(t_list list_a, t_list list_b);
int	median(t_list lst, int len);
int	cmpfunc(const void *a, const void *b);
void	if_len_3(t_list *list_a);
void	push_swap(t_list *list_a, t_list *list_b);

void	ft_putstr(char	*str);
void	*new_list(void);
int	is_empty(t_list list);
int	list_len(t_list list);
void	print_list(t_list list);
t_list	push_back(t_list list, int x);
t_list	push_front(t_list list, int x);
t_list	del_back(t_list list);
t_list	del_front(t_list list);
t_list	clear_list(t_list list);

#endif
