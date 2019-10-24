// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/uio.h>
// #include <unistd.h>
// #include <stdlib.h>
// # include <fcntl.h>
// #include "libft.h"
// #include <stdio.h>

#include "get_next_line.c"

// int read_line(char **str, int fd)
// {
// 	int end_line;
// 	char str_read[BUFF_SIZE + 1];
// 	int num;

// 	end_line = read(fd, str_read, BUFF_SIZE);
// 	str_read[end_line] = '\0';
// 	num = ft_intchr(*str, '\n');
// 	if (end_line == BUFF_SIZE)
// 	{
// 		if (num != -1)
// 		{
// 			ft_strncat(*str, str_read, num);
// 			return (num);
// 		}
// 		else
// 			return (BUFF_SIZE + read_line(str, fd));
// 	}
// 	*str = ft_strjoin(*str, str_read);
// 	return (end_line);
// }

// int read_line(char **str, int fd)
// {
// 	int end_line;
// 	char str_read[BUFF_SIZE + 1];
// 	int num;

// 	while ((end_line = read(fd, str_read, BUFF_SIZE)) == BUFF_SIZE)
// 	{
// 		str_read[end_line] = '\0';
// 		*str = ft_strjoin(*str, str_read);
// 		num = ft_intchr(*str, '\n');
// 		if (num != -1)
// 			return (num);
// 	}
// 	str_read[end_line] = '\0';
// 	num = ft_intchr(str_read, '\n');
// 	if (num != -1)
// 		ft_strncat(*str, str_read, num);
// 	else
// 		*str = ft_strjoin(*str, str_read);
// 	return (num);
// }

// int		ft_intchr(char *str, char c)
// {
// 	size_t result;

// 	result = 0;
// 	while (str[result] != c && str[result])
// 		result++;
// 	if (ft_strlen(str) == 1 && str[0] == c)
// 		return (1);
// 	return (result == ft_strlen(str) ? -1 : result);
// }

int main(int argc, char **argv)
{
	argc = 1;
	int fd = open(argv[1], O_RDONLY);
	char *str;
	k_list *ptr;
	ptr = ft_fdnew(6);

	// ft_putstr(ptr->content);
	// ft_putchar('\n');
	// ft_putnbr(ptr->file);
	// str = ft_strjoin(str, "55");
	// ft_putstr(str);
	// int l;
	// l = read_line(&str, fd);
	// 	ft_putnbr(l);
	// 	ft_putstr(str);
	// 	free(str);
	if (get_next_line(fd, &str) != - 1)
	{
		printf("%s", str);
		//free(str);
	}

}

	// char	*num;
	// char	*str;
	
	// str = ft_strnew(0);
	// if (fd_line == NULL)
	// {
	// 	if ((fd_line = ft_fdnew(fd)) == NULL)
	// 		return (-1);
	// }
	// else if (fd_line->file != fd)
	// 	gnl(fd, fd_line->next, line);
	// if (read_line(&str, fd_line->file) == 0)
	// 	return (1);
	// num = ft_strchr(str, '\n');
	// fd_line->content = ft_strdup(num);
	// ft_strdel(&num);
	// ft_putstr(str);
	// //free(*line + num);
	// return (1);