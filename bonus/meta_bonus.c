/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:21:33 by minssc            #+#    #+#             */
/*   Updated: 2022/02/25 01:36:38 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_meta	*meta_get(void)
{
	static t_meta	*meta;

	if (!meta)
		meta = (t_meta *)ft_calloc(sizeof(t_meta), 1);
	if (!meta)
		perror_exit("ft_calloc failed for meta");
	return (meta);
}

t_meta	*meta_init(void)
{
	t_meta	*m;

	m = meta_get();
	m->mlx = mlx_init();
	if (!m->mlx)
		perror_exit("mlx_init failed @meta_init");
	m->keys = (t_keys *)ft_calloc(sizeof(t_keys), 1);
	m->map = (t_map *)ft_calloc(sizeof(t_map), 1);
	m->tex_wall = (t_img *)ft_calloc(sizeof(t_img), 1);
	m->tex_empty = (t_img *)ft_calloc(sizeof(t_img), 1);
	m->tex_col = (t_img *)ft_calloc(sizeof(t_img), 1);
	m->tex_col2 = (t_img *)ft_calloc(sizeof(t_img), 1);
	m->tex_player = (t_img *)ft_calloc(sizeof(t_img), 1);
	m->tex_player2 = (t_img *)ft_calloc(sizeof(t_img), 1);
	m->tex_exit = (t_img *)ft_calloc(sizeof(t_img), 1);
	m->tex_patrol = (t_img *)ft_calloc(sizeof(t_img), 1);
	if (!m->keys || !m->map || !m->tex_wall || !m->tex_empty || !m->tex_col
		|| !m->tex_player || !m->tex_col2 || !m->tex_player2)
		perror_exit("ft_calloc failed @meta_init");
	return (m);
}

void	meta_destroy(void)
{
	t_meta	*m;

	m = meta_get();
	if (m->mlx)
	{
		texture_destroy(m);
		if (m->win)
			mlx_destroy_window(m->mlx, m->win);
		mlx_destroy_display(m->mlx);
	}
	if (m->keys)
		free(m->keys);
	if (m->map)
	{
		if (m->map->data)
			free(m->map->data);
		free(m->map);
	}
	if (m->mlx)
		free(m->mlx);
	free(m);
}
