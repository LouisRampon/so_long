/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:17:29 by lorampon          #+#    #+#             */
/*   Updated: 2022/06/18 18:10:54 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	wall_to_window(t_program program, int x, int y)
{
	t_image	img;
	
	img = ft_new_sprite(program.mlx_pointer, "assets/wall.xpm");
	mlx_put_image_to_window(program.mlx_pointer, program.window, img.pointer, TILE_SIZE * x, y * TILE_SIZE);
}

void	floor_to_window(t_program program, int x, int y)
{
	t_image	img;
	
	img = ft_new_sprite(program.mlx_pointer, "assets/floor.xpm");
	mlx_put_image_to_window(program.mlx_pointer, program.window, img.pointer, TILE_SIZE * x, y * TILE_SIZE);
}

void	perso_to_window(t_program program, int x, int y)
{
	t_image	img;
	
	img = ft_new_sprite(program.mlx_pointer, "assets/perso1.xpm");
	mlx_put_image_to_window(program.mlx_pointer, program.window, img.pointer, TILE_SIZE * x, y * TILE_SIZE);
}

void	collectible_to_window(t_program program, int x, int y)
{
	t_image	img;
	
	floor_to_window(program, x, y);
	img = ft_new_sprite(program.mlx_pointer, "assets/collectible.xpm");
	mlx_put_image_to_window(program.mlx_pointer, program.window, img.pointer, TILE_SIZE * x, y * TILE_SIZE);
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
			if (program->map.strs[y][x] == '1')
				wall_to_window(*program, x, y);
			if (program->map.strs[y][x] == '0' || program->map.strs[y][x] == 'E')
				floor_to_window(*program, x, y);
			if (program->map.strs[y][x] == 'C')
				collectible_to_window(*program, x, y);
			if (program->map.strs[y][x] == 'P')
			{
				floor_to_window(*program, x, y);
				program->map.strs[y][x] = '0';
				if (!program->map.pos.x)
				{
				program->map.pos.x = y;
				program->map.pos.y = x;
				}
			}
			x++;
		}
		y++;
	}

	perso_to_window(*program, program->map.pos.y, program->map.pos.x);
	return (*program);
}