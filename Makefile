#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/20 13:50:50 by jde-maga          #+#    #+#              #
#    Updated: 2017/02/23 17:30:30 by jde-maga         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC_PATH = src/
SRC_NAME = main.c inits.c file_parser.c get_variables.c cor_live.c cor_ld.c cor_st.c cor_add.c cor_sub.c cor_and.c cor_or.c cor_xor.c cor_zjmp.c cor_ldi.c cor_sti.c cor_fork.c cor_lld.c cor_lldi.c cor_lfork.c cor_aff.c endian_converter.c render.c
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes
NAME = corewar
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIBS = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) -lncurses $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		$(CC) -c $(CFLAGS) $< -o $@

clean :
		rm -rf $(OBJ_PATH)

fclean : clean
		rm -rf $(NAME)

re : fclean all
