/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:23:54 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/10/25 00:11:12 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	static k_list *lines;

	lines = ft_fdnew(fd);
	line = (char**)malloc(sizeof(char *));
	if (fd < 0 || line == NULL)
		return (-1);
	gnl(fd, lines, line);
	ft_putstr(*line);
	return (1);
}

int		gnl(int fd, k_list *fd_line, char **line)
{
	int		num;
	char	*str;
	fd = 1;
	str = ft_strnew(0);
	// if (fd_line == NULL)
	// {
	// 	if ((fd_line = ft_fdnew(fd)) == NULL)
	// 		return (-1);
	// }
	// else if (fd_line->file != fd)
	// 	gnl(fd, fd_line->next, line);
	if (read_line(&str, fd_line->file) == 0)
		return (-1);
	num = ft_intchr(str, '\n');
	fd_line->content = ft_strdup(str + num + 1);
	*(str + num) = '\0';
	*line = ft_strdup(str);
	free(str);
	//ft_putstr(*line);
	return (1);
}

int		read_line(char **str, int fd)
{
	int		end_line;
	char	str_read[BUFF_SIZE + 1];
	char	*tmp;

	while ((end_line = read(fd, str_read, BUFF_SIZE)) > 0)
	{
		str_read[end_line] = '\0';
		tmp = ft_strjoin(*str, str_read);
		free(*str);
		*str = tmp;
		//ft_putstr(*str);
		if (ft_intchr(*str, '\n') != -1)
			return (1);
	}
	return (0);
}

k_list	*ft_fdnew(int fd)
{
	k_list *ptr;

	ptr = NULL;
	ptr = (k_list *)malloc(sizeof(k_list));
	if (ptr == NULL || fd < 0)
		return (NULL);
	ptr->content = ft_strnew(0);
	if (ptr->content == NULL)
	{
		free(ptr);
		return (NULL);
	}
	ptr->file = fd;
	ptr->next = NULL;
	return (ptr);
}

int		ft_intchr(char *str, char c)
{
	size_t result;

	result = 0;
	while (str[result] != c && str[result])
		result++;
	return (result == ft_strlen(str) ? -1 : result);
}