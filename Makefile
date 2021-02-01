# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 11:00:45 by tsannie           #+#    #+#              #
#    Updated: 2021/02/01 12:19:17 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
CC			= @gcc
CFLAGS		= -Wall -Wextra -Werror
MLX			= ./minilibx-linux -lmlx -lXext -lX11 -lm
RM			= @rm -rf
LIBFT		= ./libft

BLACK		:= $(shell tput -Txterm setaf 0)
RED			:= $(shell tput -Txterm setaf 1)
GREEN		:= $(shell tput -Txterm setaf 2)
YELLOW		:= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	:= $(shell tput -Txterm setaf 4)
PURPLE		:= $(shell tput -Txterm setaf 5)
BLUE		:= $(shell tput -Txterm setaf 6)
WHITE		:= $(shell tput -Txterm setaf 7)
BOLD		:=$(shell tput -Txterm bold)
END			:= $(shell tput -Txterm sgr0)
NAMEC		= ${BLUE}${BOLD}c$(RED)u$(GREEN)b$(PURPLE)3D${END}
NAMELIB		= ${BLUE}${BOLD}Libft${END}

SRC			= main.c trim1.c trim2.c trim3.c error_msg.c \
trim_texture.c check_map1.c check_map2.c start_cub.c minimap.c \
display_tool1.c display_tool2.c moove_player.c raycasting1.c raycasting2.c \
raycasting3.c colision.c sprite.c bmp.c

SRC_BONUS 	= \

OBJ			= $(addprefix src/, $(SRC:.c=.o))
OBJ_BONUS	= $(addprefix src/, $(SRC_BONUS:.c=.o))

all:		$(NAME)

$(NAME): 	$(OBJ)
			@echo "${PURPLE}${BOLD}Start compile ...${END}"
			@$(MAKE) -C $(LIBFT)
			@echo "${GREEN}The $(NAMELIB) ${GREEN}has been build !${END}"
			$(CC) $(CFLAGS) -I/includes -I/minilibx-linux ./libft/libft.a -o $(NAME) $(OBJ) $(OBJ_BONUS) -Llibft -lft -L $(MLX)
			@echo "${GREEN}The game $(NAMEC) ${GREEN}has been build !${END}"

clean:
			$(RM) $(OBJ)
			@$(MAKE) clean -C $(LIBFT)
			@echo "${YELLOW}The game $(NAMEC) ${YELLOW}has been cleaned up !" \
			 "(with ${BOLD}${WHITE}$@${END}${YELLOW}) !${END}"

fclean:		clean
			$(RM) $(NAME)
			@$(MAKE) fclean -C $(LIBFT)
			@echo "${YELLOW}The game $(NAMEC) ${YELLOW}has been deleted !" \
				"(with ${BOLD}${WHITE}$@${END}${YELLOW}) !${END}"

re:			fclean all

.PHONY:		all test clean fclean re
