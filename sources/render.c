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

#include "so_long.h"

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
				mlx_put_image_to_window(m->mlx, m->win, m->tex_player->obj,
					cx * BLOCK_SIZE, cy * BLOCK_SIZE);
			else if (cur == 'E')
				mlx_put_image_to_window(m->mlx, m->win, m->tex_exit->obj,
					cx * BLOCK_SIZE, cy * BLOCK_SIZE);
			else if (cur == 'C')
				mlx_put_image_to_window(m->mlx, m->win, m->tex_col->obj,
					cx * BLOCK_SIZE, cy * BLOCK_SIZE);
		}
	}
}

void	render(t_meta *m)
{
	background(m);
	foreground(m);
}
