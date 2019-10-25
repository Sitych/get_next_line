/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:23:54 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/10/25 16:37:20 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	static	k_list *ptr;
	char	*str;

	str = ft_strnew(0);
	if (fd < 0 || line == NULL)
		return (-1);
	return (gnl(fd, &ptr, line, str));
}

int		gnl(int fd, k_list **fd_line, char **line, char *str)
{
	int		num;
	int		rtn;

	if (*fd_line == NULL)
	{
		if ((*fd_line = ft_fdnew(fd)) == NULL)
			return (-1);
	}
	else if ((*fd_line)->file != fd)
	{
		rtn = gnl(fd, &((*fd_line)->next), line, str);
		return (rtn);
	}
	rtn = read_line(&str, fd_line, 0);
	num = ft_intchr(str, '\n');
	free((*fd_line)->content);
	(*fd_line)->content = (num == -1) ? ft_strnew(0) : ft_strdup(str + num + 1);
	if (num == -1)
		*(str + num) = '\0';
	*line = ft_strdup(str);
	ft_strdel(&str);
	return (rtn);	
}

int		read_line(char **str, k_list **ptr_list, int flag)
{
	int		end_line;
	char	str_read[BUFF_SIZE + 1];
	char	*tmp;
	int		num;

	while ((end_line = read((*ptr_list)->file, str_read, BUFF_SIZE)) > 0)
	{
		str_read[end_line] = '\0';
		tmp = ft_strjoin(*str, str_read);
		free(*str);
		*str = tmp;
		if ((num = ft_intchr(*str, '\n')) != -1)
		{
			flag = 1;
			break;
		}
	}
	tmp = ft_strjoin((*ptr_list)->content, *str);
	ft_strdel(str);
	*str = tmp;
	return (flag);
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