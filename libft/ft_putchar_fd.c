#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	if (write(fd, &c, 1) == -1)
		perror("FT_PUTCHAR_FD");
}
