/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:51:22 by lorampon          #+#    #+#             */
/*   Updated: 2022/06/18 19:01:49 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include "../includes/get_next_line.h"

# define TILE_SIZE	16
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_RIGHT	124
# define KEY_LEFT	123
# define KEY_ESC	53

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	char		**strs;
	t_vector	pos;
	int			length;
	int			height;
}		t_map;

typedef struct	s_image
{
	void      *pointer;
	t_vector  size;
	char      *pixels;
	int       bits_per_pixel;
	int       line_size;
	int       endian;
}   t_image;

typedef struct	s_program
 {
	void	*mlx_pointer;
	void	*window;
	int		collec;
	int		count;
	t_image	img;
	t_map	map;
	// … etc
}				t_program;

void	move_up(t_program *program);
void	move_down(t_program *program);
void	move_right(t_program *program);
void	move_left(t_program *program);

void	ft_create_map(t_program *program, char *str);
int	nbr_collectible(char **strs);
int		map_height(char *argv);
char	**map_fill(char *argv, t_map map);

int	check_map(char *str);
int	check_char(char *strs);

t_image	ft_new_sprite(void *mlx, char *path);
t_program	map_to_window(t_program *program);

int	ft_exit(void *params);
int	ft_input(int key, void *params);

#endif