/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:44:03 by lorampon          #+#    #+#             */
/*   Updated: 2022/06/18 18:55:55 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_collectible(t_program *program)
{
	if (program->map.strs[program->map.pos.x][program->map.pos.y] == 'C')
	{
		program->collec--;
		ft_printf("collec = %d\n", program->collec);
		program->map.strs[program->map.pos.x][program->map.pos.y] = '0';
	}
}

void	check_exit(t_program *program)
{
	if (program->map.strs[program->map.pos.x][program->map.pos.y] == 'E')
	{
		if (!program->collec)
			exit(0);
	}
}

int	ft_exit(void *params)
{
	t_program *program; 
	
	program = (t_program *)params;
	exit(0);
}

int	ft_input(int key, void *params)
{
	t_program *program; 
	
	program = (t_program *)params;
	if (key == KEY_UP)
		move_up(program);
	if (key == KEY_DOWN)
		move_down(program);
	if (key == KEY_RIGHT)
		move_right(program);
	if (key == KEY_LEFT)
		move_left(program);
	if (key == KEY_ESC)
		exit(0);
	check_collectible(program);
	check_exit(program);
	map_to_window(program);
	return (0);
}
