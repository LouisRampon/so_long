/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:51:22 by lorampon          #+#    #+#             */
/*   Updated: 2022/06/30 14:02:06 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include "../includes/get_next_line.h"

# define TILE_SIZE	32
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_RIGHT	124
# define KEY_LEFT	123
# define KEY_ESC	53
# define KEY_W		13
# define KEY_S		1
# define KEY_D		2
# define KEY_A		0

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_image
{
	void		*pointer;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}	t_image;

typedef struct s_sprite
{
	t_image	wall;
	t_image	floor;
	t_image	dino;
	t_image	collectible;
	t_image	exit;
}	t_sprite;

typedef struct s_map
{
	char		**strs;
	t_vector	pos;
	size_t		length;
	size_t		height;
}		t_map;

typedef struct s_program
{
	void		*mlx_pointer;
	void		*window;
	int			collec;
	int			count;
	t_sprite	sprite;
	t_map		map;
}				t_program;

void		move_up(t_program *program);
void		move_down(t_program *program);
void		move_right(t_program *program);
void		move_left(t_program *program);
void		exit_to_window(t_program program, int x, int y);

void		floor_to_window(t_program program, int x, int y);
void		wall_to_window(t_program program, int x, int y);
void		perso_to_window(t_program program, int x, int y);
void		collectible_to_window(t_program program, int x, int y);

void		ft_create_map(t_program *program, char *str);
int			nbr_collectible(char **strs);
int			map_height(char *argv);
char		**map_fill(char *argv, t_map map);

void		ft_init_sprite(t_program *program);
t_image		ft_new_sprite(void *mlx, char *path);
t_program	map_to_window(t_program *program);
void		map_to_window_help(t_program *program, int x, int y);

int			ft_exit(void *params);
int			ft_input(int key, void *params);

int			ft_check_char(t_program program);
int			ft_check_map(t_program *program);
int			ft_check_size(t_program program);
int			ft_check_wall(t_program program);
int			ft_check_dup(t_program program, char c);
int			ft_check_p(t_program program);

#endif