#include "fdf.h"

static void	_check_lines(t_map *map, char *line, int fd)
{
	char	**axis;
	int		width;
	int		i;

	while (line)
	{
		axis = ft_split(line, ' ');
		if (!axis)
			exit_failure_map("Failed to ft_split() a line from the map!\n", \
															axis, line, fd);
		i = 0;
		width = get_width(line);
		while (i < width && check_altitude_and_color(axis[i]))
			i++;
		if (i != width)
			exit_failure_map("Exiting.\n", axis, line, fd);
		free_axis_and_line(axis, line, fd, 0);
		if (width != map->width)
			exit_failure("Found wrong line length. Exiting.\n");
		map->height++;
		line = get_next_line(fd);
	}
}

t_map	map_parser(char	*file)
{
	t_map	map;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_perror("Cannot open the file");
	line = get_next_line(fd);
	map.width = get_width(line);
	map.height = 0;
	_check_lines(&map, line, fd);
	close(fd);
	return (map);
}

static unsigned int	_get_color(char *str)
{
	ssize_t	color;

	color = DFL_COLOR;
	if (!str)
		return (color);
	if (*str == '+' || *str == '-')
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	if (*str == ',')
	{
		str += 3;
		color = ft_atoi_base16(str);
		if (color == -1)
			color = DFL_COLOR;
	}
	return (color);
}

static void	_fill_area(t_map *map, int i, int fd)
{
	int		j;
	char	*line;
	char	**axis;

	line = get_next_line(fd);
	map->points[i] = malloc(sizeof(t_point3d) * map->width);
	if (!map->points[i])
		exit_failure_area("Failed malloc()-ating the area!\n", \
											map->points, line, fd);
	axis = ft_split(line, ' ');
	if (!axis)
		exit_failure_area("Failed to ft_split() a line from the map!\n", \
														map->points, line, fd);
	j = -1;
	while (++j < map->width)
		map->points[i][j] = (t_point3d){i, map->width - 1 - j, \
							ft_atoi(axis[j]), _get_color(axis[j])};
	free_axis_and_line(axis, line, fd, 0);
}

void	make_area(char *file, t_map *map)
{
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_perror("Cannot open the file");
	map->points = malloc(sizeof(t_point3d *) * map->height);
	if (!map->points)
		exit_failure("Failed malloc()-ating the area!\n");
	i = -1;
	while (++i < map->height)
		_fill_area(map, i, fd);
	close(fd);
}
