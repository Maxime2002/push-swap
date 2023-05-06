/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:42:39 by mlangloi          #+#    #+#             */
/*   Updated: 2023/05/06 19:34:48 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	int				nb;
	int				index;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_clean(char *str);

int		execute_list(char *line, t_list **list_a, t_list **list_b);
int		execute_list2(char *line, t_list **list_a, t_list **list_b);
int		execute_list3(char *line, t_list **list_a, t_list **list_b);
int		execute_list4(char *line, t_list **list_a, t_list **list_b);
int		ft_traitement(t_list *list_a, t_list *list_b);
void	ft_result(t_list **list_a, t_list **list_b);

int		ft_strcmp(char *s1, char *s2);
void	pav2(t_list **list_a, t_list **list_b);
void	pbv2(t_list **list_a, t_list **list_b);
void	ft_putstr(char *s);
int		ft_atoi(char *str, t_list *elem);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *s);
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
void	ft_free_list(t_list *list_a, t_list *list_b);
void	ft_error(t_list *list_a, t_list *list_b, int res, char *error);
int		list_len(t_list *list);
int		find_min_index(t_list **list);
int		find_max_index(t_list **list);
t_list	*ft_add_elem(t_list *elem, int val);

#endif
