/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:44:55 by lorampon          #+#    #+#             */
/*   Updated: 2022/06/27 17:56:34 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_create_map(t_program *program, char *str)
{
	char	extension[3];

	extension[0] = str[ft_strlen(str) - 3];
	extension[1] = str[ft_strlen(str) - 2];
	extension[2] = str[ft_strlen(str) - 1];
	if (!(extension[0] == 'b' && extension[1] == 'e' && extension[2] == 'r'))
	{
		ft_printf("Error\n");
		exit (0);
	}
	program->count = 0;
	program->map.height = map_height(str);
	program->map.strs = map_fill(str, program->map);
	program->collec = nbr_collectible(program->map.strs);
	program->map.length = (ft_strlen(program->map.strs[0]) - 1);
}

int	nbr_collectible(char **strs)
{
	int	i;
	int	j;
	int	tot;

	i = 0;
	tot = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == 'C')
				tot++;
			j++;
		}
		i++;
	}
	return (tot);
}

int	map_height(char *argv)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	return (i);
}

char	**map_fill(char *argv, t_map map)
{
	int		fd;
	char	*str;
	int		i;
	char	**strs;

	i = 0;
	strs = malloc(sizeof(char *) * map.height + 1);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (strs);
	str = get_next_line(fd);
	while (str)
	{
		strs[i] = str;
		str = get_next_line(fd);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
