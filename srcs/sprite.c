/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:13:39 by lorampon          #+#    #+#             */
/*   Updated: 2022/06/27 17:22:55 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.pointer = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

void	ft_init_sprite(t_program *program)
{
	program->sprite.floor = ft_new_sprite(program->mlx_pointer,
			"assets/floor.xpm");
	program->sprite.wall = ft_new_sprite(program->mlx_pointer,
			"assets/wall.xpm");
	program->sprite.dino = ft_new_sprite(program->mlx_pointer,
			"assets/dino.xpm");
	program->sprite.collectible = ft_new_sprite(program->mlx_pointer,
			"assets/collectible.xpm");
	program->sprite.exit = ft_new_sprite(program->mlx_pointer,
			"assets/exit.xpm");
}

t_program	map_to_window(t_program *program)
{
	int		y;
	int		x;

	y = 0;
	while (program->map.strs[y])
	{
		x = 0;
		while (program->map.strs[y][x])
		{
			if (program->map.strs[y][x] == 'E')
				exit_to_window(*program, x, y);
			else if (program->map.strs[y][x] == '1')
				wall_to_window(*program, x, y);
			else if (program->map.strs[y][x] == '0')
				floor_to_window(*program, x, y);
			else if (program->map.strs[y][x] == 'C')
				collectible_to_window(*program, x, y);
			else if (program->map.strs[y][x] == 'P')
				map_to_window_help(program, x, y);
			x++;
		}
		y++;
	}
	return (*program);
}

void	map_to_window_help(t_program *program, int x, int y)
{
	floor_to_window(*program, x, y);
	perso_to_window(*program, x, y);
	program->map.strs[y][x] = '0';
	program->map.pos.x = y;
	program->map.pos.y = x;
}
