# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bngweny <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 15:08:18 by bngweny           #+#    #+#              #
#    Updated: 2018/09/06 10:49:31 by bngweny          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CC_FLAGS = -Wall -Werror -Wextra -I$(LFT_PATH)/incl -O3

LFT_PATH = ./libft
SRC_PATH = ./srcs/
INC_PATH = ./incl $(LFT_PATH)/incl
OBJ_PATH = ./obj/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_NAME = echo_built.c env.c get_pwd.c main.c set_env.c strhelp.c  unset_env.c

all: $(NAME)

$(NAME): $(OBJ)
	+$(MAKE) -C $(LFT_PATH)
	$(CC) -o $(NAME) $(OBJ) -L$(LFT_PATH) -lft


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)/bi
	$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	make -C $(LFT_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LFT_PATH) fclean
	rm -f $(NAME)

check:
	@./test.sh

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
