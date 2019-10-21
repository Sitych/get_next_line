#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
# include <fcntl.h>
#include "libft.h"
#include <stdio.h>
#define BUFF_SIZE 1

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
	int n = get_next_line(fd, &str);
	if (n)
	{
		ft_putnbr(n);
		ft_putchar('\n');
		ft_putstr(str);
	}
	close(fd);
}

// size_t	fast_strlen(const char *s)
// {
// 	size_t len;
// 	unsigned int x;

// 	len = 0;
// 	while (1) {
// 		x = *s++;
// 		if (!(x & 0xff))
// 			return len;
// 		else if (!(x & 0xff00))
// 			return (len + 1);
// 		else if (!(x & 0xff0000))
// 			return (len + 2);
// 		else if (!(x & 0xff000000))
// 			return (len + 3);
// 		len += sizeof (int);
// 	}
// }