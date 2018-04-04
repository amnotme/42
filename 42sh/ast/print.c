#include "print.h"

void	print_queue(t_queue *node)
{
    while (node)
    {
        ft_putstr(node->name);
        ft_putstr("\n");
        node = node->next;
    }
}
