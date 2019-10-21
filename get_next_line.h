/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:27:05 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/10/21 21:04:16 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

#define BUFF_SIZE 1

typedef struct		s_list
{
	char			*content;
	int				file;
	struct s_list	*next;
}					t_list;


int					ft_intchr(char *str, char c);
int					get_next_line(const int fd, char **line);
t_list				*ft_fdnew(int fd);

#endif