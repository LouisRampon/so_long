/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:28:33 by lorampon          #+#    #+#             */
/*   Updated: 2022/10/11 13:43:02 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	find_y(t_program *program)
{
	int	y;

	y = 0;
	if (program->map.height >= MAX_Y)
	{
		if (program->map.pos.x - (MAX_Y / 2) < 0)
			y = 0;
		else if (program->map.pos.x + (MAX_Y / 2) >= program->map.height)
			y = program->map.height - MAX_Y;
		else
			y = program->map.pos.x - (MAX_Y / 2);
	}
	else
		y = 0;
	return (y);
}

int	find_x(t_program *program)
{
	int	x;

	x = 0;
	if (program->map.length >= MAX_X)
	{
		if (program->map.pos.y - (MAX_X / 2) < 0)
				x = 0;
		else if (program->map.pos.y + (MAX_X / 2) >= program->map.length)
			x = program->map.length - MAX_X;
		else
			x = program->map.pos.y - (MAX_X / 2);
	}
	else
		x = 0;
	return (x);
}

void	ft_start(t_program *program)
{
	int	i;
	int	j;

	i = 0;
	if (!program->map.strs)
		return ;
	while (program->map.strs[i])
	{
		j = 0;
		while (program->map.strs[i][j])
		{
			if (program->map.strs[i][j] == 'P')
			{
				program->map.pos.x = i;
				program->map.pos.y = j;
			}
			j++;
		}
		i++;
	}
}

int	check_path(t_program program)
{
	ft_start(&program);
	if (!solve_path(program, program.map.pos.x, program.map.pos.y))
	{
		return (1);
	}
	return (0);
}

int	solve_path(t_program program, int x, int y)
{
	if (program.map.strs[x][y] == 'E')
		return (1);
	if (program.map.strs[x][y] == '2')
		return (0);
	else if (program.map.strs[x][y] != '1')
		program.map.strs[x][y] = '2';
	if (program.map.strs[x][y] != '1')
	{
		if (solve_path(program, x + 1, y))
			return (1);
		if (solve_path(program, x, y + 1))
			return (1);
		if (solve_path(program, x - 1, y))
			return (1);
		if (solve_path(program, x, y - 1))
			return (1);
		return (0);
	}
	return (0);
}
