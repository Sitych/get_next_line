/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:23:54 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/10/21 23:42:52 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int get_next_line(const int fd, char **line)
{
	static t_list *lines;

	lines = NULL;
	if (fd < 0)
		return (-1);
	return (gnl(fd, lines, line));
}

int gnl(int fd, t_list *fd_line, char **line)
{
	char **s;
	int num;

	if (*fd_line == NULL)
		if ((*fd_line = ft_fdnew(fd) == NULL)
			return (-1);
	else if (*lines->file != fd)
		gnl(fd, *fd_line->next, line);
	if ((num = read_line(s, fd_line->file) == -1)
		return (1);
}

int read_line(char **str, int fd)
{
	int end_line;
	char str_read[BUFF_SIZE + 1];
	int num;

	while ((end_line = read(fd, str_read, BUFF_SIZE)) == BUFF_SIZE)
	{
		str_read[BUFF_SIZE] = '\0';
		*str = ft_strjoin(*str, str_read);
		num = ft_intchr(*str, '\n');
		if (num != -1)
			return (num);
	}
	str_read[end_line] = '\0';
	num = ft_intchr(str_read, '\n');
	if (num != -1)
		ft_strncat(*str, str_read, num);
	else
		*str = ft_strjoin(*str, str_read);
	return (num);
}

t_list *ft_fdnew(int fd)
{
	t_list *ptr;

	ptr = NULL;
	ptr = (t_list *)malloc(sizeof(t_list));
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
	if (ft_strlen(str) == 1 && str[0] == c)
		return (1);
	return (result == ft_strlen(str) ? -1 : result);
}