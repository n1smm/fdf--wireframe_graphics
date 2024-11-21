# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 12:15:56 by tjuvan            #+#    #+#              #
#    Updated: 2023/11/08 17:14:40 by tjuvan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =  cc
CFLAGS =
NAME = libftprintf.a
SRC_FILES = \
put_char_str.c put_nbr_adress.c ft_printf.c 
OBJ_FILES = $(SRC_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)
	@echo "creating library"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@ echo "compiling obj files"

test: $(NAME)
	@$(CC) $(CFLAGS) $(prog) $< -L. -lftprintf
	@echo "compiling for test"

clean:
	@rm -f $(OBJ_FILES)
	@echo "cleaning objects"

fclean: clean
	@rm -f $(NAME)
	@echo "and the library"

re: fclean all
	@echo "repeat the process"
