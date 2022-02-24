/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:29:06 by minsunki          #+#    #+#             */
/*   Updated: 2022/02/24 18:29:06 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	background(t_meta *m)
{
	char	cur;
	int		cx;
	int		cy;

	cy = -1;
	while (++cy < m->map->y)
	{
		cx = -1;
		while (++cx < m->map->x)
		{
			cur = m->map->data[cy * (m->map->x + 1) + cx];
			if (cur == '1')
				mlx_put_image_to_window(m->mlx, m->win, m->tex_wall->obj,
					cx * BLOCK_SIZE, cy * BLOCK_SIZE);
			else
				mlx_put_image_to_window(m->mlx, m->win, m->tex_empty->obj,
					cx * BLOCK_SIZE, cy * BLOCK_SIZE);
		}
	}
}

static void	animate_ply(t_meta *m, int cy, int cx)
{
	if (m->moves % 2)
		mlx_put_image_to_window(m->mlx, m->win, m->tex_player->obj,
			cx * BLOCK_SIZE, cy * BLOCK_SIZE);
	else
		mlx_put_image_to_window(m->mlx, m->win, m->tex_player2->obj,
			cx * BLOCK_SIZE, cy * BLOCK_SIZE);
}

static void	animate_col(t_meta *m, int cy, int cx)
{
	if (m->moves % 2)
		mlx_put_image_to_window(m->mlx, m->win, m->tex_col->obj,
			cx * BLOCK_SIZE, cy * BLOCK_SIZE);
	else
		mlx_put_image_to_window(m->mlx, m->win, m->tex_col2->obj,
			cx * BLOCK_SIZE, cy * BLOCK_SIZE);
}

static void	foreground(t_meta *m)
{
	char	cur;
	int		cx;
	int		cy;

	cy = -1;
	while (++cy < m->map->y)
	{
		cx = -1;
		while (++cx < m->map->x)
		{
			cur = m->map->data[cy * (m->map->x + 1) + cx];
			if (cur == 'P')
				animate_ply(m, cy, cx);
			else if (cur == 'E')
				mlx_put_image_to_window(m->mlx, m->win, m->tex_exit->obj,
					cx * BLOCK_SIZE, cy * BLOCK_SIZE);
			else if (cur == 'C')
				animate_col(m, cy, cx);
			else if (cur == 'p')
				mlx_put_image_to_window(m->mlx, m->win, m->tex_patrol->obj,
					cx * BLOCK_SIZE, cy * BLOCK_SIZE);
		}
	}
}

void	render(t_meta *m)
{
	char	buf[4];

	buf[3] = '\0';
	background(m);
	foreground(m);
	if (m->moves > 999)
		mlx_string_put(m->mlx, m->win, 5, 20, 0xFFFFFF, "Moves: 999+");
	buf[0] = m->moves / 100 + '0';
	buf[1] = (m->moves / 10) % 10 + '0';
	buf[2] = m->moves % 10 + '0';
	mlx_string_put(m->mlx, m->win, 5, 20, 0xFFFFFF, "Moves: ");
	mlx_string_put(m->mlx, m->win, 42, 21, 0xFFFFFF, buf);
}
