/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:23:15 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 18:05:32 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

// PRINTF STRUCTURE
typedef struct s_flags
{
	int	zero;
	int	minus;
	int	width;
	int	precision;
	int	precisize;
	int	hash;
	int	space;
	int	plus;
}		t_flags;

// LIBFT STRUCTURE //
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t elementSize, size_t elementCount);
int					ft_isalnum(int character);
int					ft_isalpha(int character);
int					ft_isascii(int c);
int					ft_isdigit(int character);
int					ft_isprint(int character);
void				*ft_memchr(void *memory, int searchedChar, size_t size);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t count);
void				*ft_memmove(void *dest, const void *src, size_t nb);
void				*ft_memset(void *pointeur, int value, size_t count);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(char *src);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
unsigned int		ft_strlcpy(char *dest, const char *src, size_t size);
int					ft_strlen(const char *str);
int					ft_strncmp(const char *first, const char *second,
						size_t lenght);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strrchr(const char *str, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int character);
int					ft_toupper(int character);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_itoa(int n);
char				**ft_split(char const *str, char c);
long				ft_atol(const char *nptr);
// GET_NEXT_LINE //
char				*ft_calloc_gnl(size_t elementSize, size_t elementCount);
char				*get_next_line(int fd);
int					ft_strchr_gnl(char *str, char find);
char				*fetch_file(char *buffer, int fd);
char				*ft_reset(char *buffer);
char				*ft_line(char *buffer);
char				*ft_strjoin_gnl(char *s1, char *s2);
// PRINTF //
int					ft_printf(const char *str, ...);
int					ft_putchar(char c, t_flags *flags);
int					ft_printchar(char c);
int					ft_printstr(char *str);
int					ft_printnullstr(t_flags *flags);
int					ft_printstr_flag(char *str, t_flags *flags);
int					ft_printptr(unsigned long long ptr, t_flags *flag);
int					ft_checktype(va_list args, const char type, t_flags *flags);
char				*malloc_zero(int len, int precisize);
int					ft_putnbr(int n, t_flags *flag);
void				ft_bzero_printf(void *ptr, size_t n);
int					ft_get_hexadecimal_length(unsigned int nbr);
char				*create_array(int len, t_flags *flags);
char				*ft_puthexa(unsigned int nbr, char c, t_flags *flags);
int					ft_printhexa(unsigned int nbr, char c, t_flags *flags);
t_flags				*create_struct(void);
int					ft_setflags(t_flags *flags, const char *str);
int					ft_setflags(t_flags *flags, const char *str);
void				ft_toupper_printf(char *str);
int					ft_get_integer_length(int nbr);
int					ft_printunsigned(unsigned int nbr, t_flags *flags);
int					ft_re_setflags(t_flags *flags, const char *str,
						va_list args);
int					ft_isdigit(int character);
void				add_zero_hexa(int len, int i, char *array);
int					set_v(int n, t_flags *flags);
int					ft_integer_flag(char sign);
int					ft_int_len(long nbr);
void				add_zero(char *str, int precisize, int len);
char				*ft_itoa_printf(int n, t_flags *flag, int len);
int					integer_handler(int n, t_flags *flags);
int					justify_putflags_integer(char *str, t_flags *flags, int n);
void				print_width_flags(char *str, t_flags *flags, int n,
						int len);
int					justify_putflags_zero(char *str, t_flags *flags, int n);
int					justify_putflags_precisize(t_flags *flags, int n);
void				reversing_array(char *array, int len);
int					ft_hexaflag_left(char *str, t_flags *flags, char c,
						unsigned int nb);
int					ft_hexaflag_right_zero(char *str, t_flags *flags, char c,
						unsigned int nb);
int					ft_hexaflag_right(char *str, t_flags *flags, char c,
						unsigned int nb);
int					ft_hexaflag_zero(char *str, t_flags *flags);
int					justify_putflags_zero_ptr(char *str, t_flags *flags);
int					set_v_ptr(t_flags *flags);
void				print_width_flags_ptr(char *str, t_flags *flags, int len);
int					justify_putflags_ptr(char *str, t_flags *flags);
int					justify_putflags_precisize_ptr(t_flags *flags);
int					justify_putflags_zero2(char *str, t_flags *flags);
int					ft_getprecision(t_flags *flags, const char *str,
						va_list args);
int					ft_printnull_char_str(t_flags *flags);
#endif // LIBFT_H
