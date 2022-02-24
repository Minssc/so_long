/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmlx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 01:08:21 by minsunki          #+#    #+#             */
/*   Updated: 2022/02/23 01:08:21 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mmlx_window_init(t_meta *m)
{
	const t_res	*r = &m->res;

	m->win = mlx_new_window(m->mlx, r->x, r->y, "so_long");
	if (!m->win)
		perror_exit("mlx_new_window failed @mmlx_window_init");
}

void	mmlx_prep_framebuffer(t_meta *m)
{
	t_res	*r;

	r = &m->res;
	r->x = m->map->x * BLOCK_SIZE;
	r->y = m->map->y * BLOCK_SIZE;
}
