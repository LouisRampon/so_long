/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:46:50 by lorampon          #+#    #+#             */
/*   Updated: 2022/10/10 13:41:19 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_p(t_program program, char c)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 1;
	while (program.map.strs[i])
	{
		j = 0;
		while (program.map.strs[i][j])
		{
			if (program.map.strs[i][j] == c && p == 0)
				return (1);
			if (program.map.strs[i][j] == c)
				p = 0;
			j++;
		}
		i++;
	}
	if (p == 1)
		return (1);
	return (0);
}

int	ft_check_dup(t_program program, char c)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (program.map.strs[i])
	{
		j = 0;
		while (program.map.strs[i][j])
		{
			if (program.map.strs[i][j] == c)
				e++;
			j++;
		}
		i++;
	}
	if (!e)
		return (1);
	return (0);
}

int	ft_check_wall(t_program program)
{
	int	i;

	i = 0;
	while (program.map.strs[0][i + 1])
	{
		if (program.map.strs[0][i] != '1')
			return (1);
		if (program.map.strs[program.map.height - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < program.map.height)
	{
		if (program.map.strs[i][0] != '1')
			return (1);
		if (program.map.strs[i][program.map.length - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_size(t_program program)
{
	int		i;
	size_t	ref;

	i = 0;
	ref = (ft_strlen(program.map.strs[0]));
	while (program.map.strs[i + 1])
	{
		if (ft_strlen(program.map.strs[i]) != ref)
			return (1);
		i++;
	}
	if (ft_strlen(program.map.strs[i]) != ref - 1)
		return (1);
	if (i + 1 != program.map.height)
		return (1);
	return (0);
}

int	ft_check_char(t_program program)
{
	int	i;
	int	j;

	i = 0;
	while (program.map.strs[i])
	{
		j = 0;
		while (program.map.strs[i][j])
		{
			if (program.map.strs[i][j] == '1'
				|| program.map.strs[i][j] == '0'
				|| program.map.strs[i][j] == 'P'
				|| program.map.strs[i][j] == 'E'
				|| program.map.strs[i][j] == 'C'
				|| program.map.strs[i][j] == '\n')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
