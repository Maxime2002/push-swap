

#include "checker.h"

int	check_finish(t_list *list_a)
{
	t_list	*tmp;

	if (list_a)
	{
		while ((list_a)->next)
		{
			tmp = (list_a)->next;
			while (tmp)
			{
				if ((list_a)->value > tmp->value)
					return (-1);
				tmp = tmp->next;
			}
			list_a = (list_a)->next;
		}
	}
	else
		return (-1);
	return (0);
}

int	ft_is_double(t_list *elem)
{
	t_list	*tmp;

	if (elem)
	{
		while (elem->next)
		{
			tmp = elem->next;
			while (tmp)
			{
				if (elem->value == tmp->value)
					return (-1);
				tmp = tmp->next;
			}
			elem = elem->next;
		}
	}
	return (0);
}

void	ft_free_list(t_list *list_a, t_list *list_b)
{
	t_list	*tmp;

	while (list_a)
	{
		tmp = list_a;
		list_a = tmp->next;
		free(tmp);
	}
	while (list_b)
	{
		tmp = list_b;
		list_b = tmp->next;
		free(tmp);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1[i] == '\0')
		return (0 - s2[i]);
	if (s2[i] == '\0')
		return (s1[i]);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
