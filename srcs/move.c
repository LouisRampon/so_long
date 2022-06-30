/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:42:27 by lorampon          #+#    #+#             */
/*   Updated: 2022/06/27 17:09:30 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_program *program)
{
	if (program->map.strs[program->map.pos.x - 1][program->map.pos.y] == '1')
		return ;
	floor_to_window(*program, program->map.pos.y, program->map.pos.x);
	program->map.pos.x = program->map.pos.x - 1;
	program->count++;
	perso_to_window(*program, program->map.pos.y, program->map.pos.x);
	ft_printf("nbr of move = %d\n", program->count);
}

void	move_down(t_program *program)
{
	if (program->map.strs[program->map.pos.x + 1][program->map.pos.y] == '1')
		return ;
	floor_to_window(*program, program->map.pos.y, program->map.pos.x);
	program->map.pos.x = program->map.pos.x + 1;
	program->count++;
	perso_to_window(*program, program->map.pos.y, program->map.pos.x);
	ft_printf("nbr of move = %d\n", program->count);
}

void	move_right(t_program *program)
{
	if (program->map.strs[program->map.pos.x][program->map.pos.y + 1] == '1')
		return ;
	floor_to_window(*program, program->map.pos.y, program->map.pos.x);
	program->map.pos.y = program->map.pos.y + 1;
	program->count++;
	perso_to_window(*program, program->map.pos.y, program->map.pos.x);
	ft_printf("nbr of move = %d\n", program->count);
}

void	move_left(t_program *program)
{
	if (program->map.strs[program->map.pos.x][program->map.pos.y - 1] == '1')
		return ;
	floor_to_window(*program, program->map.pos.y, program->map.pos.x);
	program->map.pos.y = program->map.pos.y - 1;
	program->count++;
	perso_to_window(*program, program->map.pos.y, program->map.pos.x);
	ft_printf("nbr of move = %d\n", program->count);
}
