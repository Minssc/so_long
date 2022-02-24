/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:49:07 by minsunki          #+#    #+#             */
/*   Updated: 2022/02/24 19:49:07 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ply_get_pos(t_meta *m, t_pnt *cp)
{
	int		cidx;

	cidx = (int)(ft_strchr(m->map->data, 'P') - m->map->data);
	cp->y = cidx / (m->map->x + 1);
	cp->x = cidx % (m->map->x + 1);
}

static void	check_collectables(char *cur)
{
	while (*cur)
	{
		if (*cur == 'C')
		{
			printf("Player has not colleced all the collectables :<\n");
			return ;
		}
		cur++;
	}
	printf("Player has collected all the collectables!\n");
}

static void	exit_reached(t_meta *m)
{
	m->exit_reached = 1;
	printf("Player has reached the exit!\n");
	check_collectables(m->map->data);
	printf("Final move count is: %d\nPress ESC to quit\n", ++m->moves);
}

void	player_move(t_meta *m, int d)
{
	const t_map	*map = m->map;
	t_pnt		cp;
	t_pnt		bp;

	ply_get_pos(m, &cp);
	ply_get_pos(m, &bp);
	if (m->exit_reached
		|| (d == UP && map->data[--cp.y * (map->x + 1) + cp.x] == '1')
		|| (d == DOWN && map->data[++cp.y * (map->x + 1) + cp.x] == '1')
		|| (d == LEFT && map->data[cp.y * (map->x + 1) + --cp.x] == '1')
		|| (d == RIGHT && map->data[cp.y * (map->x + 1) + ++cp.x] == '1'))
		return ;
	if (map->data[cp.y * (map->x + 1) + cp.x] == 'E')
		exit_reached(m);
	else
	{
		ft_putstr_fd("total moves: ", 1);
		ft_putnbr_fd(++m->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	map->data[bp.y * (map->x + 1) + bp.x] = '0';
	map->data[cp.y * (map->x + 1) + cp.x] = 'P';
}
