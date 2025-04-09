#include "libft.h"

static int	_ft_output_length_cntl(int flag)
{
	static int	output_length;

	if (!flag)
		output_length = 0;
	else if (flag > 0)
		output_length += flag;
	return (output_length);
}

static void	_ft_printf(va_list args, const char *str)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp)
	{
		if (*tmp == '%')
		{
			tmp++;
			if (*tmp == 'c')
			{
				ft_putchar_fd(va_arg(args, int), FD);
				_ft_output_length_cntl(1);
			}
		}
		else
		{
			ft_putchar_fd(*tmp, FD);
			_ft_output_length_cntl(1);
		}
		tmp++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	if (write(FD, NULL, 0) == -1)
	{
		perror("STDIN_NO is closed");
		exit(EXIT_FAILURE);
	}
	va_start(args, str);
	_ft_output_length_cntl(0);
	_ft_printf(args, str);
	va_end(args);
	return (_ft_output_length_cntl(-2));
}
