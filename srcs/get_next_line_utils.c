/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:26:13 by lorampon          #+#    #+#             */
/*   Updated: 2022/06/27 17:16:22 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen1(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strnlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*ft_strdup1(const char *src, size_t start)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(*src) * (ft_strlen1(src) + 1) - start);
	if (!dest ||!src)
		return (0);
	while (src[start + i])
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strndup(const char *src)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(sizeof(*src) * (ft_strnlen(src) + 2));
	if (!dest || !src)
		return (0);
	while (i < (ft_strnlen(src)) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}

int	ft_strnchr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
