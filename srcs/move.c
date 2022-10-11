/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:42:27 by lorampon          #+#    #+#             */
/*   Updated: 2022/10/11 13:35:31 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_program *program)
{
	if (program->map.strs[program->map.pos.x - 1][program->map.pos.y] == '1')
		return ;
	check_collectible(program, program->map.pos.x - 1, program->map.pos.y);
	check_exit(program, program->map.pos.x - 1, program->map.pos.y);
	program->map.strs[program->map.pos.x - 1][program->map.pos.y] = 'P';
	program->map.pos.x = program->map.pos.x - 1;
	program->count++;
	map_to_window(program);
	ft_printf("nbr of move = %d\n", program->count);
}

void	move_down(t_program *program)
{
	if (program->map.strs[program->map.pos.x + 1][program->map.pos.y] == '1')
		return ;
	check_collectible(program, program->map.pos.x + 1, program->map.pos.y);
	check_exit(program, program->map.pos.x + 1, program->map.pos.y);
	program->map.strs[program->map.pos.x + 1][program->map.pos.y] = 'P';
	program->map.pos.x = program->map.pos.x + 1;
	program->count++;
	map_to_window(program);
	ft_printf("nbr of move = %d\n", program->count);
}

void	move_right(t_program *program)
{
	if (program->map.strs[program->map.pos.x][program->map.pos.y + 1] == '1')
		return ;
	check_collectible(program, program->map.pos.x, program->map.pos.y + 1);
	check_exit(program, program->map.pos.x, program->map.pos.y + 1);
	program->map.strs[program->map.pos.x][program->map.pos.y + 1] = 'P';
	program->map.pos.y = program->map.pos.y + 1;
	program->count++;
	map_to_window(program);
	ft_printf("nbr of move = %d\n", program->count);
}

void	move_left(t_program *program)
{
	if (program->map.strs[program->map.pos.x][program->map.pos.y - 1] == '1')
		return ;
	check_collectible(program, program->map.pos.x, program->map.pos.y - 1);
	check_exit(program, program->map.pos.x, program->map.pos.y - 1);
	program->map.strs[program->map.pos.x][program->map.pos.y - 1] = 'P';
	program->map.pos.y = program->map.pos.y - 1;
	program->count++;
	map_to_window(program);
	ft_printf("nbr of move = %d\n", program->count);
}
