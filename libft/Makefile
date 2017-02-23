#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 16:44:29 by jde-maga          #+#    #+#              #
#    Updated: 2016/05/27 14:17:11 by jde-maga         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC_PATH = src/
SRC_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strerror.c ft_memswap.c ft_sort_int.c ft_strrev.c ft_lstpushback.c ft_abs.c ft_realloc.c ft_multi_strchr.c ft_putnbr_int.c ft_size_int.c ft_size_uint.c ft_putnbr_int.c ft_putnbr_uint.c ft_size_ullong.c ft_putnbr_ullong.c ft_putnbr_ulong.c ft_size_ulong.c ft_putnbr_long.c ft_size_long.c ft_size_llong.c ft_putnbr_llong.c ft_ispos.c ft_itoa_long.c ft_itoa_ulong.c ft_strnew_uchar.c utf_byte_size.c ft_strlen_ls.c ft_strcat_uchar.c ft_strlen_uchar.c ft_size_int_binary.c ft_atoi_long.c ft_isint.c\
get_next_line/get_next_line.c\
ft_printf/ft_printf.c ft_printf/string_parser.c ft_printf/ftprintf_struct_init.c ft_printf/next_arg_test.c\
ft_printf/print_flags.c ft_printf/print_pad.c ft_printf/print_precision.c\
ft_printf/parser_c.c ft_printf/print_c.c ft_printf/print_lc.c\
ft_printf/parser_d.c ft_printf/print_d.c\
ft_printf/parser_o.c ft_printf/print_o.c\
ft_printf/parser_s.c ft_printf/print_s.c ft_printf/print_ls.c\
ft_printf/parser_u.c ft_printf/print_u.c\
ft_printf/parser_x.c ft_printf/print_x.c\
ft_printf/parser_p.c ft_printf/print_p.c\
ft_printf/print_utf_char.c
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes
NAME = libft.a
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all : $(NAME)

$(NAME) : $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@mkdir $(OBJ_PATH)get_next_line 2> /dev/null || true
		@mkdir $(OBJ_PATH)ft_printf 2> /dev/null || true
		$(CC) -c $(CFLAGS) $< -o $@

clean :
		rm -rf $(OBJ_PATH)

fclean : clean
		rm -rf $(NAME)

re : fclean all
