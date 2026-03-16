#include "queue.h"

t_node	*ft_create_node(void *content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;

	return (node);
}

int	ft_queue_size(t_node *first_node)
{
	t_node	*current;
	int		count;

	count = 0;
	current = first_node;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}

void	ft_clear_queue(t_node **start_node, void (*del)(void*))
{
	t_node	*current;
	t_node	*to_del;

	if (!start_node || !del)
		return ;

	current = *start_node;
	while (current)
	{
		to_del = current;
		current = to_del->next;
		del(to_del->content);
		free(to_del);
	}
	*start_node = NULL;
}

void	ft_add_front(t_node **node_start, t_node *new)
{
	new->next = *node_start;
	*node_start = new;
}

void	ft_add_back(t_node **node_start, t_node *new)
{
	if (!node_start || !new)
		return ;
	if (*node_start)
		ft_lstlast(*node_start)->next = new;
	else
		*node_start = new;
}
