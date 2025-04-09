#include "fdf.h"

static void	my_mlx_pixel_put(t_data *data, t_point p, unsigned int color)
{
	char	*dst;

	if (p.x < 0 || p.x >= WIDTH || p.y < 0 || p.y >= HEIGHT)
		return ;
	dst = data->addr + (p.y * data->line_length + p.x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

t_point	project(t_point3d p3d, t_map *map)
{
	const float	angle = PI / 6.0f;
	t_point		p2d;

	p2d.x = map->offset_x + map->scale * (p3d.x - p3d.y);
	p2d.y = map->offset_y + map->scale * ((p3d.x + p3d.y) * sin(angle) - p3d.z);
	return (p2d);
}

static void	_init_vars(int *err, t_point *s, t_point start, t_point end)
{
	*err = abs(end.x - start.x) - abs(end.y - start.y);
	if (start.x < end.x)
		s->x = 1;
	else
		s->x = -1;
	if (start.y < end.y)
		s->y = 1;
	else
		s->y = -1;
}

void	bres_line(t_data *mlx, t_point start, t_point end, unsigned int color)
{
	const t_point	d = (t_point){abs(end.x - start.x), abs(end.y - start.y)};
	t_point			s;
	int				err;
	int				e2;

	_init_vars(&err, &s, start, end);
	while (1)
	{
		if (start.x < 0 || start.x >= WIDTH || start.y < 0 || start.y >= HEIGHT)
			break ;
		my_mlx_pixel_put(mlx, (t_point){start.x, start.y}, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = 2 * err;
		if (e2 >= -d.y)
		{
			err -= d.y;
			start.x += s.x;
		}
		if (e2 <= d.x)
		{
			err += d.x;
			start.y += s.y;
		}
	}
}

void	render_map(t_data *mlx, t_map *map)
{
	t_point	p1;
	t_point	p2;
	int		x;
	int		y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			p1 = project(map->points[y][x], map);
			if (x + 1 < map->width)
			{
				p2 = project(map->points[y][x + 1], map);
				bres_line(mlx, p1, p2, map->points[y][x].color);
			}
			if (y + 1 < map->height)
			{
				p2 = project(map->points[y + 1][x], map);
				bres_line(mlx, p1, p2, map->points[y][x].color);
			}
		}
	}
}
