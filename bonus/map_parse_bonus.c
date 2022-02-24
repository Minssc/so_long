/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:53:46 by minsunki          #+#    #+#             */
/*   Updated: 2022/02/24 21:53:46 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	map_trim(t_meta *m)
{
	int		i;
	char	*tmp;

	i = 0;
	while (m->map->data[i] && m->map->data[i] == '\n')
		++i;
	if (i)
	{
		tmp = m->map->data;
		m->map->data = ft_strdup(m->map->data + i);
		free(tmp);
	}
	i = (int)ft_strlen(m->map->data) - 1;
	while (i >= 0 && m->map->data[i] == '\n')
		--i;
	if (i != (int)ft_strlen(m->map->data) - 1)
	{
		tmp = m->map->data;
		m->map->data[i + 1] = '\0';
		m->map->data = ft_strdup(m->map->data);
		free(tmp);
	}
	if (!m->map->data)
		perror_exit(".ber is empty");
}

void	map_parse(t_meta *m, char *ber_file)
{
	ssize_t	r;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		fd;

	fd = open(ber_file, O_RDONLY);
	if (fd < 0)
		perror_exit("failed to open @map_parse");
	while (1)
	{
		r = read(fd, buf, BUFF_SIZE);
		if (r <= 0)
			break ;
		buf[r] = '\0';
		tmp = m->map->data;
		m->map->data = ft_strjoin(m->map->data, buf);
		if (tmp)
			free(tmp);
	}
	if (r < 0)
		perror_exit("read failed @map_parse");
	map_trim(m);
	m->map->dlen = ft_strlen(m->map->data);
	close(fd);
}
