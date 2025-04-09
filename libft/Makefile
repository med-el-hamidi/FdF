NAME := libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror

PATH_MLX := mlx_linux/

HEADER := libft.h
SRCS :=	ft_isdigit.c \
		ft_atoi.c \
		ft_atoi_base16.c \
		ft_bzero.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strdup.c \
		ft_split.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		get_next_line_utils.c \
		get_next_line.c \
		ft_printf.c

OBJS :=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I/usr/include -I../$(PATH_MLX) -O3 -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean
