NAME := fdf

CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

PATH_MLX := mlx_linux/
LIBMLX := $(PATH_MLX)libmlx_Linux.a

PATH_LIBFT := libft/
LIBFT := $(PATH_LIBFT)libft.a
HEADER_LIBFT := $(PATH_LIBFT)libft.h
LIBFT_SRCS :=	$(PATH_LIBFT)ft_isdigit.c \
				$(PATH_LIBFT)ft_atoi.c \
				$(PATH_LIBFT)ft_atoi_base16.c \
				$(PATH_LIBFT)ft_bzero.c \
				$(PATH_LIBFT)ft_strlen.c \
				$(PATH_LIBFT)ft_strlcpy.c \
				$(PATH_LIBFT)ft_strncmp.c \
				$(PATH_LIBFT)ft_strdup.c \
				$(PATH_LIBFT)ft_split.c \
				$(PATH_LIBFT)ft_putstr_fd.c \
				$(PATH_LIBFT)ft_putchar_fd.c \
				$(PATH_LIBFT)get_next_line_utils.c \
				$(PATH_LIBFT)get_next_line.c \
				$(PATH_LIBFT)ft_printf.c

HEADER := fdf.h
SRCS :=	errors.c \
		input.c \
		map.c \
		hooks.c \
		render.c \
		utils.c \
		main.c
OBJS :=	$(SRCS:.c=.o)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(PATH_LIBFT) -lft -L$(PATH_MLX) -lmlx_Linux -L/usr/lib -I$(PATH_MLX) -lXext -lX11 -lm -lz -o $@

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I/usr/include -I$(PATH_MLX) -O3 -c $< -o $@

$(LIBFT): $(LIBFT_SRCS) $(HEADER_LIBFT)
	make -C $(PATH_LIBFT)

all: $(NAME)

$(LIBMLX):
	make -C $(PATH_MLX)

clean:
	make -C $(PATH_MLX) clean
	make -C $(PATH_LIBFT) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(PATH_LIBFT) fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean
