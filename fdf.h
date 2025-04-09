#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include "mlx_linux/mlx.h"

# define PI 3.14159265358979323846
# define ESC_RED "\x1b[31m"
# define ESC_RESET "\x1b[0m"

# define EXT ".fdf"
# define USAGE "USAGE: ./fdf <filename.fdf>\n"

# define HEIGHT 1080
# define WIDTH 1920
# define SCALE 0.1
# define DFL_COLOR 0x00ffffff

# define ESC 65307

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_point3d
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_point3d;

typedef struct s_map
{
	int			width;
	int			height;
	int			offset_x;
	int			offset_y;
	float		scale;
	t_point3d	**points;
}	t_map;

typedef struct s_data
{
	int		bpp;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
}	t_data;

void	exit_failure(char *msg);
void	exit_perror(char *msg);
void	free_axis_and_line(char **axis, char *line, int fd, int cleanup);
void	exit_failure_map(char *msg, char **axis, char *line, int fd);
void	exit_failure_area(char *msg, t_point3d **area, char *line, int fd);

void	file_checker(char *file);
t_map	map_parser(char	*file);
void	make_area(char *file, t_map *map);

int		hook_key(int keycode, t_data *param);
int		close_win(t_data *vars);

void	setup_map_view( t_map *map);
int		get_width(char *line);
int		check_altitude_and_color(char *str);
void	bres_line(t_data *data, t_point start, t_point end, unsigned int color);
void	render_map(t_data *data, t_map *map);
#endif
