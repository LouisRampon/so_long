/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:22:44 by lorampon          #+#    #+#             */
/*   Updated: 2022/06/27 17:56:40 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc != 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_create_map(&program, argv[1]);
	if (ft_check_map(&program))
	{
		ft_printf("Error\n");
		exit(0);
	}
	program.mlx_pointer = mlx_init();
	program.window = mlx_new_window(program.mlx_pointer,
			program.map.length * TILE_SIZE,
			program.map.height * TILE_SIZE, "Hi");
	ft_init_sprite(&program);
	map_to_window(&program);
	mlx_key_hook(program.window, *ft_input, &program);
	mlx_hook(program.window, 17, 0, *ft_exit, &program);
	mlx_loop(program.mlx_pointer);
}

int	ft_check_map(t_program *program)
{
	if (ft_check_char(*program))
		return (1);
	if (ft_check_size(*program))
		return (1);
	if (ft_check_wall(*program))
		return (1);
	if (ft_check_dup(*program, 'C') || ft_check_dup(*program, 'E'))
		return (1);
	if (ft_check_p(*program))
		return (1);
	return (0);
}
