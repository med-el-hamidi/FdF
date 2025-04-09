#include "fdf.h"

int	hook_key(int keycode, t_data *param)
{
	if (ESC == keycode)
		close_win(param);
	return (0);
}

int	close_win(t_data *param)
{
	mlx_destroy_image(param->mlx, param->img);
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	if (param->mlx)
		free(param->mlx);
	exit(EXIT_SUCCESS);
}
