#include "fdf.h"

int	get_width(char *line)
{
	int		len;
	int		f;
	size_t	i;

	if (!line)
		return (0);
	len = 0;
	f = 1;
	i = -1;
	while (line[++i])
	{
		if (f && ft_isdigit(line[i]))
		{
			f = 0;
			len++;
		}
		else if (line[i] == ' ')
			f = 1;
	}
	return (len);
}

static int	_check_color(char *str)
{
	int	i;

	if (!ft_strncmp(str, "0x", 2) || !ft_strncmp(str, "0X", 2))
	{
		str += 2;
		i = 0;
		while (++i <= 8 && *str && (ft_isdigit(*str)
				|| (*str >= 'a' && *str <= 'f')
				|| (*str >= 'A' && *str <= 'F')))
			str++;
		if ((!*str || *str == '\n') && i > 1 && i <= 9)
			return (1);
		ft_putstr_fd(ESC_RED"NOT_COLOR: "ESC_RESET"Found wrong color value "\
					"(Try TRGB (max. 4 Bytes), ex. "\
					"<altitude>,0x00ffffff in HEX). ", 2);
	}
	else
		ft_putstr_fd(ESC_RED"NOT_HEX: "ESC_RESET"Found wrong color value "\
					"(Try TRGB, ex. <altitude>,0x00ffffff in HEX). ", 2);
	return (0);
}

int	check_altitude_and_color(char *str)
{
	if (!str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
			str++;
	}
	if (!*str || *str == '\n')
		return (1);
	else if (*str == ',')
		return (_check_color(++str));
	else
		ft_putstr_fd(ESC_RED"NOT_INT: "ESC_RESET \
					"Found wrong altitude value. ", 2);
	return (0);
}

void	setup_map_view(t_map *map)
{
	float		projected_width;
	float		projected_height;
	float		scale_x;
	float		scale_y;

	projected_width = abs(map->width - map->height);
	projected_height = fabs((map->width + map->height) * sin(PI / 6.0f));
	scale_x = WIDTH / projected_width;
	scale_y = HEIGHT / projected_height;
	map->scale = fmin(scale_x, scale_y) * SCALE;
	if (map->scale < 30)
		map->scale *= 2;
	if (map->scale < 8)
		map->scale *= 2;
	map->offset_x = (WIDTH - (map->scale * projected_width)) / 2;
	map->offset_y = (HEIGHT - (map->scale * projected_height)) / 1.2;
}
