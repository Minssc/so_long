/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 01:19:41 by minsunki          #+#    #+#             */
/*   Updated: 2022/02/23 01:19:41 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hook_destroy(t_meta *m)
{
	m->exit_flag = 1;
	return (0);
}

int	hook_keypress(int kc, t_meta *m)
{
	if (kc == KC_ESC)
		m->keys->esc = 1;
	else if (kc == KC_W)
		m->keys->w = 1;
	else if (kc == KC_A)
		m->keys->a = 1;
	else if (kc == KC_S)
		m->keys->s = 1;
	else if (kc == KC_D)
		m->keys->d = 1;
	return (0);
}

int	hook_keyrelease(int kc, t_meta *m)
{
	if (kc == KC_ESC)
		m->keys->esc = 0;
	else if (kc == KC_W)
	{
		m->keys->w = 0;
		player_move(m, UP);
	}
	else if (kc == KC_A)
	{
		m->keys->a = 0;
		player_move(m, LEFT);
	}
	else if (kc == KC_S)
	{
		m->keys->s = 0;
		player_move(m, DOWN);
	}
	else if (kc == KC_D)
	{
		m->keys->d = 0;
		player_move(m, RIGHT);
	}
	return (0);
}

static void	think_about_exit(t_meta *m)
{
	if (m->keys->esc)
		m->exit_flag = 1;
	if (m->exit_flag && !m->keys->esc && !m->keys->w && !m->keys->a
		&& !m->keys->s && !m->keys->d)
		mexit(0);
}

int	hook_think(t_meta *m)
{	
	think_about_exit(m);
	render(m);
	return (0);
}
