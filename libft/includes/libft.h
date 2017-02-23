/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:12:45 by jde-maga          #+#    #+#             */
/*   Updated: 2016/06/30 19:36:10 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <wchar.h>
# include <get_next_line.h>
# include <ft_printf.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

long			ft_atoi_long(const char *str);
int				ft_isint(char *s);
int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_ispos(long n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *ptr, int value, size_t num);
void			*ft_strrchr(const char *s, int c);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *s1, const char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_strsplit(char const *s, char c);
char			*ft_strnew(size_t size);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			*ft_itoa(int n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
struct s_list	*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
struct s_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			*ft_strerror(int errnum);
void			ft_memswap(void *a, void *b, size_t size, size_t start);
void			ft_sort_int(int *array, int size, int c);
void			ft_strrev(char *str);
void			ft_lstpushback(t_list **alst, t_list *new);
void			*ft_realloc(void *ptr, size_t size);
int				ft_abs(int c);
int				ft_size_int(int n);
int				ft_size_long(long n);
int				ft_size_uint(unsigned int u);
int				ft_size_ulong(unsigned long n);
int				ft_size_ullong(unsigned long long u);
int				ft_size_llong(long long n);
void			ft_putnbr_int(int n);
void			ft_putnbr_long(long n);
void			ft_putnbr_uint(unsigned int n);
void			ft_putnbr_ullong(unsigned long long n);
void			ft_putnbr_ulong(unsigned long n);
void			ft_putnbr_llong(long long n);
char			*ft_itoa_long(long n);
char			*ft_itoa_ulong(unsigned long n);
unsigned char	*ft_strnew_uchar(size_t size);
int				ft_strlen_uchar(unsigned char *s);
int				utf_byte_size(unsigned int c);
int				ft_strlen_ls(const wint_t *ls);
unsigned char	*ft_strcat_uchar(unsigned char *s1, unsigned char *s2);
int				size_int_binary(int c);

#endif
