/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorampon <lorampon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:55:09 by lorampon          #+#    #+#             */
/*   Updated: 2022/06/15 16:44:18 by lorampon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_strjoin1(char *s1, char *s2);
size_t	ft_strlen1(const char *str);
int		ft_strnchr(const char *str);
char	*ft_strdup1(const char *src, size_t start);
char	*ft_strndup(const char *src);
size_t	ft_strnlen(const char *str);
char	*ft_buff_to_string(char *buff, char *str);
char	*ft_parse_string(char **str);

#endif