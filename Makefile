# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 11:00:45 by tsannie           #+#    #+#              #
#    Updated: 2021/01/11 17:53:43 by tsannie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
CC			= @gcc
CFLAGS		= #-Wall -Wextra -Werror
MLX			= -lmlx -lm -framework OpenGL -framework AppKit
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

SRC			= main.c trim.c error_msg.c tools_for_dev.c trim_texture.c

SRC_BONUS 	= \

OBJ			= $(addprefix src/, $(SRC:.c=.o))
OBJ_BONUS	= $(addprefix src/, $(SRC_BONUS:.c=.o))

all:		$(NAME)

$(NAME): 	$(OBJ)
			@echo "${PURPLE}${BOLD}Start compile ...${END}"
			@$(MAKE) -C $(LIBFT)
			@echo "${GREEN}The $(NAMELIB) ${GREEN}has been build !${END}"
			$(CC) $(OBJ) $(OBJ_BONUS) -I/includes $(CFLAGS) $(MLX) ./libft/libft.a -o $(NAME)
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

test:		all clean

.PHONY:		all test clean fclean re
