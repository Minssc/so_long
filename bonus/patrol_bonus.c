/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 01:23:18 by minsunki          #+#    #+#             */
/*   Updated: 2022/02/25 02:08:10 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*empty_space_exists(char *d)
{
	while (*d)
	{
		if (*d == '0')
			return (d);
		d++;
	}
	return (0);
}

void	patrol_spawn(t_meta *m)
{
	char	*def;
	int		sp;
	int		tries;
	int		rv;

	tries = 10;
	def = empty_space_exists(m->map->data);
	if (!def)
		return ;
	srand(time(0));
	sp = (int)(def - m->map->data);
	while (--tries)
	{
		rv = rand() % m->map->dlen;
		if (m->map->data[rv] == '0')
			sp = rv;
	}
	m->map->data[sp] = 'p';
}

static void	pat_get_pos(t_meta *m, t_pnt *cp)
{
	int		cidx;

	cidx = (int)(ft_strchr(m->map->data, 'p') - m->map->data);
	cp->y = cidx / (m->map->x + 1);
	cp->x = cidx % (m->map->x + 1);
}

static void	game_over(t_meta *m)
{
	m->exit_reached = 1;
	printf("The blind patrol caught the player... HOW!\n");
	printf("Total Moves: %d\n", m->moves);
	printf("Press ESC to quit\n");
}

void	patrol_move(t_meta *m)
{
	const t_map	*map = m->map;
	const int	d = rand() % 4;
	t_pnt		cp;
	t_pnt		bp;

	pat_get_pos(m, &cp);
	pat_get_pos(m, &bp);
	if (m->exit_reached
		|| (d == UP && map->data[--cp.y * (map->x + 1) + cp.x] != '0')
		|| (d == DOWN && map->data[++cp.y * (map->x + 1) + cp.x] != '0')
		|| (d == LEFT && map->data[cp.y * (map->x + 1) + --cp.x] != '0')
		|| (d == RIGHT && map->data[cp.y * (map->x + 1) + ++cp.x] != '0'))
	{
		if (map->data[cp.y * (map->x + 1) + cp.x] == 'P')
			game_over(m);
		else
			return ;
	}
	map->data[bp.y * (map->x + 1) + bp.x] = '0';
	map->data[cp.y * (map->x + 1) + cp.x] = 'p';
}
