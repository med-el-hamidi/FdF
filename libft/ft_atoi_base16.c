#include "libft.h"

static int	isvalid(int c, int baselen)
{
	const char	*lcbase = "0123456789abcdef";
	const char	*ucbase = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < baselen)
	{
		if (c == lcbase[i] || c == ucbase[i])
			return (1);
		i++;
	}
	return (0);
}

ssize_t	ft_atoi_base16(char *str)
{
	ssize_t	res;

	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str)
	{
		if (*str == '\n')
			break ;
		if (!isvalid(*str, 16))
			return (-1);
		res *= 16;
		if (*str >= '0' && *str <= '9')
			res += *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			res += *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			res += *str - 'A' + 10;
		str++;
	}
	return (res);
}
