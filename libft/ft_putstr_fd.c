#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	if (write(fd, s, ft_strlen(s)) == -1)
		perror("FT_PUTSTR_FD");
}
