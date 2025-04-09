#include "libft.h"

t_list	*ft_lstlast(t_list *list)
{
	t_list	*ptr;

	if (!list)
		return (NULL);
	ptr = list;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

int	found_new_line(t_list *list)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			if ('\n' == list->buffer[i])
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

int	get_length_new_line(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			if ('\n' == list->buffer[i])
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		list = list->next;
	}
	return (len);
}

void	ft_lstclear(t_list **list)
{
	t_list	*ptr;

	if (!(*list))
		return ;
	while (*list)
	{
		ptr = (*list)->next;
		free((*list)->buffer);
		free(*list);
		*list = ptr;
	}
	*list = NULL;
}

void	safe_free(t_list **list, t_list *node)
{
	ft_lstclear(list);
	if (node->buffer[0])
		*list = node;
	else
	{
		free(node->buffer);
		free(node);
	}
}
