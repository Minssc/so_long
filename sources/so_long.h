/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:10:12 by minssc            #+#    #+#             */
/*   Updated: 2022/02/25 02:26:44 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define BUFF_SIZE 512
# define BLOCK_SIZE 32

# define PI 3.141592653589793
# define RADIAN 0.0174532925199433
# define UP 0
# define DOWN 2
# define LEFT 1
# define RIGHT 3

# define KC_W 119
# define KC_A 97
# define KC_S 115
# define KC_D 100
# define KC_LA 65361
# define KC_UA 65362
# define KC_RA 65363
# define KC_DA 65364
# define KC_ESC 65307
# define KC_CTRL 65513
# define KC_SHIFT 65505
# define KC_SPACE 32

typedef unsigned char	t_byte;
typedef unsigned int	t_argb;

typedef struct s_pnt
{
	int			x;
	int			y;
}				t_pnt;

typedef t_pnt			t_res;

typedef struct s_vec
{
	double		x;
	double		y;
}				t_vec;

// map struct 
// x,y resolution

typedef struct s_map
{
	int			x;
	int			y;
	char		*data;
	int			dlen;
}				t_map;

// keyboard struct
// wasd
// arrow_left, arrow_up, arrow_right, arrow_down;
// space

typedef struct s_keys
{
	t_byte		esc;
	t_byte		w;
	t_byte		a;
	t_byte		s;
	t_byte		d;
}				t_keys;

// img struct 
// ptr to obj,addr of img 
// bits per pixel 
// llen 
// endianness

typedef struct s_img
{
	void		*obj;
	char		*addr;
	int			bpp;
	int			llen;
	int			endi;
}				t_img;

// meta struct
// resolution
// mlx, mlx window pointer
// pointer to kb struct
// pointer to map struct

typedef struct s_meta
{
	int			moves;
	int			exit_reached;
	t_res		res;
	void		*mlx;
	void		*win;
	t_keys		*keys;
	t_map		*map;
	int			exit_flag;
	t_img		*tex_wall;
	t_img		*tex_empty;
	t_img		*tex_col;
	t_img		*tex_player;
	t_img		*tex_exit;
}				t_meta;

// meta.c
t_meta	*meta_init(void);
t_meta	*meta_get(void);
void	meta_destroy(void);

// map_parse.c
void	map_parse(t_meta *m, char *ber_file);

// map_validate.c
void	map_validate(t_meta *m);

// mexit.c
void	mexit(int ec);
void	perror_exit(char *str);

// hook.c
int		hook_destroy(t_meta *m);
int		hook_keypress(int kc, t_meta *m);
int		hook_keyrelease(int kc, t_meta *m);
int		hook_think(t_meta *m);

// mmlx.c
void	mmlx_window_init(t_meta *m);
void	mmlx_prep_framebuffer(t_meta *m);

// render.c
void	render(t_meta *m);

// texture.c
void	texture_init(t_meta *m);
void	texture_destroy(t_meta *m);

// player.c
void	player_move(t_meta *m, int dir);

#endif