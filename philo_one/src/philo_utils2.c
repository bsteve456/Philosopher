#include "philo_one.h"

void	display_msg(int id, int msg, long time, t_waiter *waiter)
{
	(void)waiter;
		if (msg == 1)
			has_afork(id, time);
		else if (msg == 2)
		{
			is_eating(id, time);
//			waiter->last_eat[id - 1] = time;
		}
		else if (msg == 4)
			is_sleeping(id, time);
		else if (msg == 5)
			is_thinking(id, time);
}

t_msg	*msgnew(int id, int msg, long time)
{
	t_msg *new;

	new = 0;
	if(!(new = (t_msg *)malloc(sizeof(t_msg) * 1)))
		return (NULL);
	new->id = id;
	new->msg = msg;
	new->time = time;
	new->next = NULL;
	return (new);
}

void	msgadd_back(t_waiter *waiter, t_msg *new)
{
	static t_msg *last_msg = 0;

	if (last_msg == 0)
		last_msg = waiter->msg;
	if (!last_msg)
		last_msg = new;
	else
	{
		last_msg->next = new;
		last_msg = new;
	}
}
