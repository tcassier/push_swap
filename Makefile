# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcassier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 11:19:07 by tcassier          #+#    #+#              #
#    Updated: 2017/12/07 21:30:32 by tcassier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME_1 = checker
NAME_2 = push_swap

CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./src
SRCS_1 = $(addprefix $(SRC_PATH)/, $(SRC_1))
SRCS_2 = $(addprefix $(SRC_PATH)/, $(SRC_2))
SRC_1 = checker.c
SRC_2 = push_swap.c

OBJ_PATH = ./obj
OBJS_1 = $(addprefix $(OBJ_PATH)/, $(OBJ_1))
OBJS_2 = $(addprefix $(OBJ_PATH)/, $(OBJ_2))
OBJ_1 = $(SRC_1:.c=.o)
OBJ_2 = $(SRC_2:.c=.o)

INC_PATH = ./includes
INCS = $(addprefix $(INC_PATH)/, $(INC))
INC = push_swap.h     \
	  checker.h       \
	  libft.h

LFT_PATH = ./libft
LFT_FLAG = -L $(LFT_PATH) -lft

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ_PATH) $(INCS) $(OBJS_1) $(SRCS_1) lft
	$(CC) -o $@ $(OBJS_1) $(LFT_FLAG) -I $(INC_PATH)

$(NAME_2): $(OBJ_PATH) $(INCS) $(OBJS_2) $(SRCS_2) lft
	$(CC) -o $@ $(OBJS_2) $(LFT_FLAG) -I $(INC_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH) $(INCS)
	$(CC) -c $< -o $@ -I $(INC_PATH)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean: clean_lft
	@rm -f $(OBJS)
	@rm -rf $(OBJ_PATH)

fclean: clean fclean_lft
	@rm -f $(NAME_1)
	@rm -f $(NAME_2)

lft:
	@make -C $(LFT_PATH) all

clean_lft:
	@make -C $(LFT_PATH) clean

fclean_lft:
	@make -C $(LFT_PATH) fclean

re: fclean all
