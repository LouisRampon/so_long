/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:44:03 by lorampon          #+#    #+#             */
/*   Updated: 2022/10/10 13:08:11 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_collectible(t_program *program, int x, int y)
{
	if (program->map.strs[x][y] == 'C')
	{
		program->collec--;
		ft_printf("collec = %d\n", program->collec);
		program->map.strs[x][y] = '0';
	}
}

void	check_exit(t_program *program, int x, int y)
{
	if (program->map.strs[x][y] == 'E')
	{
		if (!program->collec)
			exit(0);
		if (!program->check_exit)
			program->check_exit++;
	}
}

void	ft_free_map(t_program *program)
{
	int		i;

	i = 0;
	while (program->map.strs[i])
	{
		free(program->map.strs[i]);
		i++;
	}
	free(program->map.strs);
}

int	ft_exit(void *params)
{
	t_program	*program;

	program = (t_program *)params;
	mlx_destroy_window(program->mlx_pointer, program->window);
	mlx_destroy_image(program->mlx_pointer,
		program->sprite.collectible.pointer);
	mlx_destroy_image(program->mlx_pointer, program->sprite.dino.pointer);
	mlx_destroy_image(program->mlx_pointer, program->sprite.exit.pointer);
	mlx_destroy_image(program->mlx_pointer, program->sprite.wall.pointer);
	mlx_destroy_image(program->mlx_pointer, program->sprite.floor.pointer);
	ft_free_map(program);
	exit(0);
}

int	ft_input(int key, void *params)
{
	t_program	*program;

	program = (t_program *)params;
	if (key == KEY_UP || key == KEY_W)
		move_up(program);
	if (key == KEY_DOWN || key == KEY_S)
		move_down(program);
	if (key == KEY_RIGHT || key == KEY_D)
		move_right(program);
	if (key == KEY_LEFT || key == KEY_A)
		move_left(program);
	if (key == KEY_ESC)
		exit(0);
	return (0);
}
