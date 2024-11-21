# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thiew <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 12:56:21 by thiew             #+#    #+#              #
#    Updated: 2024/04/04 17:33:00 by tjuvan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g  -Wall -Wextra -Werror 
AFTERFLAGS = -Lmlx_linux -lmlx_linux -L/usr/lib -lmlx_linux -lX11 -lXext -lm -lz # -lmlx
NAME = fdf
BONUS_NAME = fdf_bonus
HEADER = fdf.h
SRC_FILES = read_file.c draw.c color_managment.c utils_fdf.c color_creation.c rotation_depth.c\
			hook_events.c draw_utils.c valid_map.c \
			./gnl_finished/get_next_line_utils.c \
			./gnl_finished/get_next_line.c
SRC_MAIN = main.c $(SRC_FILES)
SRC_BONUS = main_bonus.c $(SRC_FILES)

OBJ_FILES = $(SRC_FILES:%.c=%.o)
OBJ_MAIN = $(SRC_MAIN:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

LIBFT = ./final_libft/libft.a
LIBFTDIR = ./final_libft

PRINTF = ./final_printf/libftprintf.a
PRINTFDIR = ./final_printf

MLX = ./mlx_linux/libmlx.a
MLXDIR = ./mlx_linux

LIBS = -L$(LIBFTDIR) -L$(PRINTFDIR) -L$(MLXDIR) -lft -lftprintf -lmlx -lXext -lX11 -lm -lz
INC = -I./final_libft -I./final_printf -I./mlx_linux -I./gnl_finished

all: $(NAME) 

bonus: $(BONUS_NAME)

$(NAME): $(OBJ_MAIN) $(LIBFT) $(PRINTF) $(MLX)
	rm -f main_bonus.o
	#rm -f $(NAME) 
	$(CC) $(CFLAGS) $(OBJ_MAIN) $(LIBS) $(INC) -o $(NAME) 

$(BONUS_NAME): $(OBJ_BONUS) $(LIBFT) $(PRINTF) $(MLX)
	rm -f main.o
	#rm -f $(NAME) 
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBS) $(INC) -o $(BONUS_NAME) 

#$(CC) $(CFLAGS) $(OBJ_FILES) ./final_libft/libft.a ./final_printf/libftprintf.a ./mlx_linux/libmlx_Linux.a $(AFTERFLAGS) -o $(NAME) $(size)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(PRINTF):
	$(MAKE) -C $(PRINTFDIR)

$(MLX):
	$(MAKE) -C $(MLXDIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)


clean:
	$(MAKE) -C ./final_libft fclean
	$(MAKE) -C ./final_printf fclean
	$(MAKE) -C ./mlx_linux clean
	rm -f $(OBJ_MAIN)
	rm -f $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

