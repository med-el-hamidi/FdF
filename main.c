#include "fdf.h"

static void	free_map(t_map *map)
{
	t_point3d	**points;
	int			i;

	points = map->points;
	i = -1;
	while (++i < map->height)
		free(points[i]);
	free(map->points);
}

static void	_cleanup_mlx(t_data *vars)
{
	if (!vars)
		return ;
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

static void	_exit_clean(char *msg, t_data *vars, t_map *map)
{
	free_map(map);
	_cleanup_mlx(vars);
	exit_failure(msg);
}

static void	_init_mlx(t_data *vars, char *title, t_map *map)
{
	if (!vars)
		_exit_clean(ESC_RED"Error: "ESC_RESET"Failed to init mlx!\n", \
															NULL, map);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		_exit_clean(ESC_RED"Error: "ESC_RESET"Failed to init mlx!\n", \
															NULL, map);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, title);
	if (!vars->win)
		_exit_clean(ESC_RED"Error: "ESC_RESET"mlx_new_window failed!\n", \
																vars, map);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img)
		_exit_clean(ESC_RED"Error: "ESC_RESET"mlx_new_image failed!\n", \
																vars, map);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bpp, &vars->line_length, \
																&vars->endian);
	if (!vars->addr)
		_exit_clean(ESC_RED"Error: "ESC_RESET"mlx_get_data_addr failed!\n", \
																	vars, map);
}

int	main(int argc, char *argv[])
{
	char	*file;
	t_data	vars;
	t_map	map;

	if (argc != 2)
		exit_failure(USAGE);
	file = argv[1];
	file_checker(file);
	map = map_parser(file);
	setup_map_view(&map);
	make_area(file, &map);
	_init_mlx(&vars, file, &map);
	ft_bzero(vars.addr, WIDTH * HEIGHT * (vars.bpp / 8));
	render_map(&vars, &map);
	free_map(&map);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_key_hook(vars.win, hook_key, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_win, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
