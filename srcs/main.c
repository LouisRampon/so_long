/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:22:44 by lorampon          #+#    #+#             */
/*   Updated: 2022/06/18 18:48:38 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;
	
	img.pointer = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.pointer, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

int	main(int argc, char **argv)
{
	t_program	program;
	
	if (argc != 2)
		return (0);
	ft_create_map(&program, argv[1]);
	program.mlx_pointer = mlx_init();
	program.window = mlx_new_window(program.mlx_pointer, program.map.length, program.map.height, "Hi");
	map_to_window(&program);
	mlx_key_hook(program.window, *ft_input, &program);
	mlx_hook(program.window, 17, 0, *ft_exit, &program);
	mlx_loop(program.mlx_pointer);
}
