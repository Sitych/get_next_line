/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:27:05 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/10/22 00:36:15 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1

typedef struct		k_list
{
	char			*content;
	int				file;
	struct k_list	*next;
}					k_list;


int					ft_intchr(char *str, char c);
int					get_next_line(const int fd, char **line);
k_list				*ft_fdnew(int fd);
int					gnl(int fd, t_list *fd_line, char **line);
int					read_line(char **str, int fd);

#endif