/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:00:06 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/02 18:26:07 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int main ()
{
	t_list lia;
	t_list lib;

	lia = new_list();
	lib = new_list();
	lia = push_front(lia, 1);
	lia = push_front(lia, 2);
	lia = push_front(lia, 6);
	//lia = push_front(lia, 4);
	
	print_list(lia);
	push_swap(&lia, &lib);
	print_list(lia);
	
	return 0;
}
