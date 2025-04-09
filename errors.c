#include "fdf.h"

void	exit_failure(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	exit_perror(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	free_axis_and_line(char **axis, char *line, int fd, int cleanup)
{
	char	**tmp;

	tmp = axis;
	if (tmp)
	{
		while (*tmp)
			free(*tmp++);
		free(axis);
	}
	if (!cleanup)
		free(line);
	else
	{
		while (line)
		{
			free(line);
			line = get_next_line(fd);
		}
	}
}

void	exit_failure_map(char *msg, char **axis, char *line, int fd)
{
	free_axis_and_line(axis, line, fd, 1);
	close(fd);
	exit_failure(msg);
}

void	exit_failure_area(char *msg, t_point3d **area, char *line, int fd)
{
	t_point3d	**tmp;

	tmp = area;
	if (tmp)
	{
		while (*tmp)
			free(*tmp++);
		free(area);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	exit_failure(msg);
}
