/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:22:44 by lorampon          #+#    #+#             */
/*   Updated: 2022/10/10 13:41:03 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_program	program;

	(void)argv;
	if (argc != 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_create_map(&program, argv[1]);
	if (ft_check_map(&program))
		exit(0);
	ft_create_map(&program, argv[1]);
	program.mlx_pointer = mlx_init();
	ft_new_window(&program);
	ft_start(&program);
	ft_init_sprite(&program);
	map_to_window(&program);
	mlx_key_hook(program.window, *ft_input, &program);
	mlx_hook(program.window, 17, 0, *ft_exit, &program);
	mlx_loop(program.mlx_pointer);
}

void	ft_new_window(t_program *program)
{
	if (program->map.height >= MAX_Y || program->map.length >= MAX_X)
	{
		program->window = mlx_new_window(program->mlx_pointer,
				MAX_X * TILE_SIZE, MAX_Y * TILE_SIZE, "Hi");
	}
	else
	{
		program->window = mlx_new_window(program->mlx_pointer,
				program->map.length * TILE_SIZE,
				program->map.height * TILE_SIZE, "Hi");
	}
}

int	ft_check_map(t_program *program)
{
	if (!program->map.strs[0])
		return (1);
	if (ft_check_char(*program))
	{
		ft_printf("Error\n Mauvais Char\n");
		return (1);
	}
	if (ft_check_size(*program))
	{
		ft_printf("Error\n Mauvaise Taille\n");
		return (1);
	}
	if (ft_check_wall(*program))
	{
		ft_printf("Error\n Mauvais Mur\n");
		return (1);
	}
	if (ft_check_map_help(program))
		return (1);
	return (0);
}

int	ft_check_map_help(t_program *program)
{
	if (ft_check_dup(*program, 'C'))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (ft_check_p(*program, 'P') || ft_check_p(*program, 'E'))
	{
		ft_printf("Error\n Double perso ou sortie\n");
		return (1);
	}
	if (check_path(*program))
	{
		ft_printf("Error\n Pas de Chemin possible\n");
		return (1);
	}
	return (0);
}
