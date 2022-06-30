/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:26:04 by lorampon          #+#    #+#             */
/*   Updated: 2022/06/27 17:16:15 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str[1024] = {NULL};
	char		*temp;
	char		buff[BUFFER_SIZE + 1];
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 1024)
		return (NULL);
	i = 1;
	while (!ft_strnchr(str[fd]) && i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if ((i == -1) || (i == 0 && !str[fd]))
			return (NULL);
		buff[i] = '\0';
		str[fd] = ft_buff_to_string(buff, str[fd]);
	}
	if (ft_strnchr(str[fd]))
		return (ft_parse_string(&str[fd]));
	if (str[fd] && !str[fd][0])
		temp = NULL;
	else
		temp = ft_strdup1(str[fd], 0);
	free(str[fd]);
	str[fd] = NULL;
	return (temp);
}

char	*ft_parse_string(char **str)
{
	char	*output;
	char	*temp;

	output = ft_strndup(*str);
	temp = *str;
	*str = ft_strdup1(temp, ft_strnlen(temp) + 1);
	free(temp);
	return (output);
}

char	*ft_buff_to_string(char *buff, char *str)
{
	char	*temp;

	if (str)
	{
		temp = str;
		str = ft_strjoin1(temp, buff);
		if (temp)
			free(temp);
	}
	else
		str = ft_strdup1(buff, 0);
	return (str);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen1(s1) + ft_strlen1(s2) + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
