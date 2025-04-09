#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# define FD 1

typedef struct s_list
{
	char			*buffer;
	struct s_list	*next;
}	t_list;

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
ssize_t	ft_atoi_base16(char *str);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);

int		ft_printf(const char *str, ...);

t_list	*ft_lstlast(t_list *list);
int		found_new_line(t_list *list);
int		get_length_new_line(t_list *list);
void	ft_lstclear(t_list **list);
void	safe_free(t_list **list, t_list *clean_node);

char	*get_next_line(int fd);
#endif
