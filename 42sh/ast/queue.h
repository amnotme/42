/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 23:16:01 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/03/22 18:55:35 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "../header.h"

typedef struct		s_queue
{
	char			*name;
	struct s_queue	*next;
}					t_queue;

t_queue				*queue_new(char *name);
t_queue				*queue_enqueue(t_queue *head, t_queue *node);
t_queue				*queue_dequeue(t_queue *head);
t_queue				*queue_dequeue_front(t_queue *head);
int					queue_len(t_queue *head);

#endif
