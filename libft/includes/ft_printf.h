/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:23:43 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/19 11:58:29 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <libft.h>

# define FLAG_LETTERS "0-+ #*"
# define PAD_LETTERS "0123456789"
# define PRECISION_LETTERS ".0123456789"
# define MODIFIER_LETTERS "hljz"
# define TYPE_LETTERS "sSpdDioOuUxXcC%"
# define NUMBER_TYPES "dDiouUxX"

# define BYPASS_UNDEFINED_BEHAVIOR 1

typedef struct	s_printf_flags
{
	int zero;
	int minus;
	int plus;
	int space;
	int hashtag;
}				t_printf_flags;

typedef struct	s_printf_format
{
	struct s_printf_flags	flags;
	int						pad_size;
	int						precision_size;
	int						modifier;
	char					type;
	int						hide_print;
	int						nwcard;
}				t_printf_format;

int				ft_printf(char *input_string, ...);

int				parser_c(t_printf_format format, va_list varlist);
int				parser_s(t_printf_format format, va_list varlist);
int				parser_o(t_printf_format format, va_list varlist);
int				parser_x(t_printf_format format, va_list varlist);
int				parser_u(t_printf_format format, va_list varlist);
int				parser_d(t_printf_format format, va_list varlist);
int				parser_p(t_printf_format format, va_list varlist);

int				print_x(t_printf_format format, unsigned long x);
int				print_u(t_printf_format format, unsigned long u);
int				print_d(t_printf_format *format, long d);
int				print_o(t_printf_format format, unsigned long o);
int				print_c(t_printf_format format, unsigned char c);
int				print_s(t_printf_format format, char *s);
int				print_p(t_printf_format format, void *p);

int				print_ls(t_printf_format *format, wint_t *ls);
int				print_lc(t_printf_format *format, wint_t c);
int				print_utf_char(unsigned int c);
int				ft_binary_size(int c);

void			print_pad(int pad_size, int zpad, int nwcard);
void			print_precision(int precision_size);
void			print_flags(t_printf_format format, int d);

char			ft_printf_hexa_table(int i, char type);
char			*string_parser(char *s, t_printf_format *format,
								va_list varlist);
char			hexa_ascii_table(unsigned long ipt);
void			ftprintf_struct_init(t_printf_format *format);

void			get_pad(int pad_size, int zpad, char **str);
void			get_precision(int precision_size, char **str);
void			get_flags(t_printf_format *format, int pos, char **str);
void			get_utf_char(unsigned int c, unsigned char **str);

int				test_next_arg(char *ipt_string, va_list varlist);

#endif
