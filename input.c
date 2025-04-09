#include "fdf.h"

static int	_isempty_line(char *line)
{
	if (!line)
		return (1);
	while ((*line >= 9 && *line <= 13) || *line == ' ')
		line++;
	if (!*line)
		return (1);
	return (0);
}

static void	_isfile_has_data(int fd)
{
	char	*line;
	int		exit;
	int		in;

	exit = 0;
	in = 0;
	line = get_next_line(fd);
	while (line)
	{
		in = 1;
		if (_isempty_line(line))
			exit = 1;
		free(line);
		line = get_next_line(fd);
	}
	if (exit)
		exit_failure("Found an empty line.\n");
	if (!in && !line)
		exit_failure("No data found.\n");
}

void	file_checker(char *file)
{
	const int	ext_len = ft_strlen(EXT);
	int			fd;
	int			i;

	if (!ft_strncmp(file, "\0", 1))
		exit_failure(USAGE);
	i = 0;
	while (file[i])
		i++;
	if (i < (ext_len + 1) || ft_strncmp(file + (i - ext_len), EXT, ext_len))
		exit_failure(USAGE);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_perror("Cannot open the file");
	_isfile_has_data(fd);
	close (fd);
}
