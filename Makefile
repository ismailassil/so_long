# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassil <iassil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 10:59:27 by iassil            #+#    #+#              #
#    Updated: 2024/02/17 03:11:30 by iassil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CC			+=	-Wall -Wextra -Werror
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
RM			=	rm -f
NAME		=	so_long
NAME_BONUS	=	so_long_bonus
HEADER_H	=	_header/so_long.h			mandatory/get_next_line/get_next_line.h
HB_H		=	_header/so_long_bonus.h		bonus/get_next_line/get_next_line_bonus.h

SRC			=	mandatory/utils/mlx/_mlx.c		mandatory/utils/mlx/_render.c			mandatory/utils/mlx/_mlx_utils.c		mandatory/utils/mlx/_utils.c		\
				mandatory/utils/mlx/_check.c	mandatory/utils/parsing/valid_path.c	mandatory/utils/parsing/valid_path_v2.c	mandatory/utils/parsing/parse_map.c	\
				mandatory/utils/lib/ft_putnbr.c	mandatory/utils/lib/ft_substr.c			mandatory/utils/lib/ft_lstadd_back.c	mandatory/utils/lib/ft_strdup.c		\
				mandatory/so_long.c				mandatory/get_next_line/get_next_line.c	mandatory/get_next_line/get_next_line_utils.c
				

SRC_BONUS	=	bonus/utils/mlx/_mlx_bonus.c			bonus/utils/mlx/_render_bonus.c			bonus/utils/mlx/_mlx_utils_bonus.c	bonus/utils/mlx/_utils_bonus.c				\
				bonus/utils/parsing/_parse_map_bonus.c	bonus/utils/parsing/_valid_path_bonus.c	bonus/utils/mlx/_check_bonus.c		bonus/utils/mlx/_render_next_frame_bonus.c	\
				bonus/utils/lib/ft_itoa_bonus.c			bonus/utils/lib/ft_putnbr_bonus.c		bonus/utils/lib/ft_substr_bonus.c	bonus/utils/mlx/_move_enemy_bonus.c			\
				bonus/utils/lib/ft_strdup_bonus.c		bonus/so_long_bonus.c					bonus/utils/parsing/valid_path_v2_bonus.c	bonus/get_next_line/get_next_line_bonus.c		\
				bonus/get_next_line/get_next_line_utils_bonus.c	

OBJ			=	$(SRC:.c=.o)
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

########### Goal Target
all: $(NAME)

bonus: $(NAME_BONUS)

########### Built Functions
mandatory/%.o: mandatory/%.c $(HEADER_H)
	@$(CC) -c $< -o $@

bonus/%.o: bonus/%.c $(HB_H)
	@$(CC) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compilation of the Objects files...$(RESET)"
	@$(CC) $(MLXFLAGS) $^ -o $@
	@echo "$(GREEN)[====Executable file Compiled Successfully!====]$(RESET)"

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "$(YELLOW)Compilation of the Objects files...$(RESET)"
	@$(CC) $(MLXFLAGS) $^ -o $@
	@echo "$(GREEN)[====Executable file Compiled Successfully!====]$(RESET)"

clean:
	@echo "$(YELLOW)Removing Object files...$(RESET)"
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@echo "$(GREEN)[====Object files removed successfully!====]$(RESET)"

fclean: clean
	@echo "$(YELLOW)Removing Executable...$(RESET)"
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)[====Executable files removed successfully!====]$(RESET)"

re: fclean all

.PHONY: all fclean clean re

########## Define ANSI escape codes for colors
GREEN=	\033[32m
YELLOW=	\033[0;33m
RESET=	\033[0m		# No Color
