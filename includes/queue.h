#ifndef QUEUE_H
# define QUEUE_H

typedef struct s_node
{
	void	*content;
	t_queue	*next;

}	t_node;

t_node	*ft_create_node(void *content);
int		ft_queue_size(t_node *first_node);
void	ft_clear_queue(t_node **start_node, void (*del)(void*));
void	ft_add_front(t_node **node_start, t_node *new);
void	ft_add_back(t_node **node_start, t_node *new);

#endif