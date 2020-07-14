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

/*t_msg	*msgnew(int id, int msg, long time)
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
}*/

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char *data;

	if (!(data = (unsigned char *)malloc(size * count)))
		return (NULL);
//	ft_bzero((void *)data, size*count);
	memset((void *)data, 0, size * count);
	return (data);
}

t_msg *fill_msg()
{
	t_msg *res;
	int i;

	if (!(res = (t_msg *)malloc(sizeof(t_msg) * RESET)))
		return (0);
	i = 0;
	while (i < RESET)
	{
		res[i].msg = 0;
		res[i].time = 0;
		i++;
	}
	return (res);
}
