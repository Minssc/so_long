/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:30:32 by minsunki          #+#    #+#             */
/*   Updated: 2022/02/24 18:30:32 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	_load(t_meta *m, t_img *tex, char *file)
{
	int	rubbish;

	tex->obj = mlx_xpm_file_to_image(m->mlx, file, &rubbish, &rubbish);
	if (!tex->obj)
		perror_exit("mlx_xpm_file_to_image failed @texture_load");
	tex->addr = mlx_get_data_addr(tex->obj, &tex->bpp, &tex->llen, &tex->endi);
	if (!tex->addr)
		perror_exit("mlx_get_data_addr failed @texture_load");
	tex->bypp = tex->bpp >> 3;
}

void	texture_init(t_meta *m)
{
	_load(m, m->tex_wall, "textures/wall.xpm");
	_load(m, m->tex_empty, "textures/empty.xpm");
	_load(m, m->tex_col, "textures/collectable.xpm");
	_load(m, m->tex_col2, "textures/collectable2.xpm");
	_load(m, m->tex_player, "textures/player.xpm");
	_load(m, m->tex_player2, "textures/player2.xpm");
	_load(m, m->tex_exit, "textures/exit.xpm");
	_load(m, m->tex_patrol, "textures/patrol.xpm");
}

static void	_destroy(t_meta *m, t_img *tex)
{
	if (tex->obj)
		mlx_destroy_image(m->mlx, tex->obj);
	free(tex);
}

void	texture_destroy(t_meta *m)
{
	if (m->tex_wall)
		_destroy(m, m->tex_wall);
	if (m->tex_empty)
		_destroy(m, m->tex_empty);
	if (m->tex_col)
		_destroy(m, m->tex_col);
	if (m->tex_col2)
		_destroy(m, m->tex_col2);
	if (m->tex_player)
		_destroy(m, m->tex_player);
	if (m->tex_player2)
		_destroy(m, m->tex_player2);
	if (m->tex_exit)
		_destroy(m, m->tex_exit);
	if (m->tex_patrol)
		_destroy(m, m->tex_patrol);
	m->tex_wall = 0;
	m->tex_empty = 0;
	m->tex_col = 0;
	m->tex_col2 = 0;
	m->tex_player = 0;
	m->tex_player2 = 0;
	m->tex_exit = 0;
	m->tex_patrol = 0;
}
