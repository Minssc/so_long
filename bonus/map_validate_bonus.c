/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:58:32 by minsunki          #+#    #+#             */
/*   Updated: 2022/02/25 00:56:20 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	validate_wall(t_meta *m)
{
	int	cx;
	int	cy;

	cx = -1;
	cy = 0;
	while (++cx < m->map->x)
		if (m->map->data[cy * (m->map->x + 1) + cx] != '1')
			perror_exit("map is not walled properly");
	cx = -1;
	cy = m->map->y - 1;
	while (++cx < m->map->x)
		if (m->map->data[cy * (m->map->x + 1) + cx] != '1')
			perror_exit("map is not walled properly");
	cx = 0;
	cy = -1;
	while (++cy < m->map->y)
		if (m->map->data[cy * (m->map->x + 1) + cx] != '1')
			perror_exit("map is not walled properly");
	cx = m->map->x - 1;
	cy = -1;
	while (++cy < m->map->y)
		if (m->map->data[cy * (m->map->x + 1) + cx] != '1')
			perror_exit("map is not walled properly");
}

static void	validate_shape(t_meta *m)
{
	int	i;

	if (!ft_strchr(m->map->data, '\n'))
		perror_exit("map cannot be single line");
	m->map->x = (int)(ft_strchr(m->map->data, '\n') - m->map->data);
	i = 1 + m->map->x * 2;
	m->map->y = 1;
	while (i < m->map->dlen)
	{
		if (m->map->data[i] != '\n')
			break ;
		m->map->y++;
		i += m->map->x + 1;
	}
	if (i == m->map->dlen)
		m->map->y++;
	if (i != m->map->dlen && i < m->map->dlen)
		perror_exit("map is not rectangular");
	validate_wall(m);
}

static void	check_exists(int e)
{
	if ((e & 0b001) == 0)
		perror_exit("missing player start position");
	if ((e & 0b010) == 0)
		perror_exit("missing collectable(s)");
	if ((e & 0b100) == 0)
		perror_exit("missing exit(s)");
}

void	map_validate(t_meta *m)
{
	char	*cur;
	int		exists;

	cur = m->map->data;
	exists = 0;
	while (*cur)
	{
		if (*cur != '0' && *cur != '1' && *cur != 'C' && *cur != 'E'
			&& *cur != 'P' && *cur != '\n')
			perror_exit("invalid character found in .ber");
		if (*cur == 'P' && (exists & 0b001) == 0)
			exists |= 0b001;
		else if (*cur == 'P' && (exists & 0b001) == 1)
			*cur = '0';
		if (*cur == 'C')
			exists |= 0b010;
		if (*cur == 'E')
			exists |= 0b100;
		cur++;
	}
	validate_shape(m);
	check_exists(exists);
}
