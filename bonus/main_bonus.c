/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:09:39 by minsunki          #+#    #+#             */
/*   Updated: 2022/02/25 02:30:50 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_usage(char *farg)
{
	printf("Error\nUsage: %s [.ber file]\n", farg);
	exit(1);
}

static int	check_map_extension(char *fn)
{
	const int	len = ft_strlen(fn);

	if (fn[len - 1] != 'r' || fn[len - 2] != 'e')
		return (0);
	if (fn[len - 3] != 'b' || fn[len - 4] != '.')
		return (0);
	return (1);
}

static void	so_long(t_meta *m)
{
	mmlx_window_init(m);
	mlx_hook(m->win, 2, 1L << 0, hook_keypress, m);
	mlx_hook(m->win, 3, 1L << 1, hook_keyrelease, m);
	mlx_hook(m->win, 17, 0, hook_destroy, m);
	mlx_loop_hook(m->mlx, hook_think, m);
	mlx_loop(m->mlx);
}

int	main(int argc, char *argv[])
{
	t_meta	*m;

	if (argc != 2 || !check_map_extension(argv[1]))
		print_usage(argv[0]);
	m = meta_init();
	texture_init(m);
	map_parse(m, argv[1]);
	map_validate(m);
	mmlx_prep_framebuffer(m);
	patrol_spawn(m);
	so_long(m);
	return (0);
}
