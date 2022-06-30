/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:17:29 by lorampon          #+#    #+#             */
/*   Updated: 2022/06/27 17:13:06 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	floor_to_window(t_program program, int x, int y)
{
	mlx_put_image_to_window(program.mlx_pointer, program.window,
		program.sprite.floor.pointer, TILE_SIZE * x, y * TILE_SIZE);
}

void	wall_to_window(t_program program, int x, int y)
{
	floor_to_window(program, x, y);
	mlx_put_image_to_window(program.mlx_pointer, program.window,
		program.sprite.wall.pointer, TILE_SIZE * x, y * TILE_SIZE);
}

void	perso_to_window(t_program program, int x, int y)
{
	floor_to_window(program, x, y);
	mlx_put_image_to_window(program.mlx_pointer, program.window,
		program.sprite.dino.pointer, TILE_SIZE * x, y * TILE_SIZE);
}

void	collectible_to_window(t_program program, int x, int y)
{
	floor_to_window(program, x, y);
	mlx_put_image_to_window(program.mlx_pointer, program.window,
		program.sprite.collectible.pointer, TILE_SIZE * x, y * TILE_SIZE);
}

void	exit_to_window(t_program program, int x, int y)
{
	mlx_put_image_to_window(program.mlx_pointer, program.window,
		program.sprite.exit.pointer, TILE_SIZE * x, y * TILE_SIZE);
}
