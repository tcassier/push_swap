# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcassier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 11:19:07 by tcassier          #+#    #+#              #
#    Updated: 2017/12/11 13:58:35 by tcassier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME_1 = checker
NAME_2 = push_swap

CC = clang
CFLAGS = -Wall -Werror -Wextra -I$(INC_PATH) -I$(LFT_INC_PATH)

SRC_1_PATH = ./src_checker/
SRC_2_PATH = ./src_push_swap/
SRCS_1 = $(addprefix $(SRC_1_PATH), $(SRC_1))
SRCS_2 = $(addprefix $(SRC_2_PATH), $(SRC_2))
SRC_1 = checker.c      \
		exec_pa.c      \
		exec_pb.c      \
		exec_ra.c      \
		exec_rb.c      \
		exec_rr.c      \
		exec_rra.c     \
		exec_rrb.c     \
		exec_rrr.c     \
		exec_sa.c      \
		exec_sb.c      \
		exec_ss.c      \
		failure.c      \
		print_stack.c  \
		process.c
SRC_2 = push_swap.c

OBJ_PATH = ./obj/
OBJS_1 = $(addprefix $(OBJ_PATH), $(OBJ_1))
OBJS_2 = $(addprefix $(OBJ_PATH), $(OBJ_2))
OBJ_1 = $(SRC_1:.c=.o)
OBJ_2 = $(SRC_2:.c=.o)

INC_PATH = ./includes/
INCS_1 = $(addprefix $(INC_PATH), $(INC_1))
INCS_1 = $(addprefix $(INC_PATH), $(INC_2))
INC_1 = checker.h
INC_2 = push_swap.h

LFT_INC_PATH = $(LFT_PATH)includes/
LFT_PATH = ./libft/
LFT_FLAG = -L $(LFT_PATH) -lft

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ_PATH) $(OBJS_1)
	@make -C $(LFT_PATH) all
	@$(CC) $(CFLAGS) -o $@ $(OBJS_1) $(LFT_FLAG)

$(NAME_2): $(OBJ_PATH) $(OBJS_2)
	@make -C $(LFT_PATH) all
	@$(CC) $(CFLAGS) -o $@ $(OBJS_2) $(LFT_FLAG)

$(OBJ_PATH)%.o: $(SRC_1_PATH)%.c $(INCS_1)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(SRC_2_PATH)%.c $(INCS_2)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean: clean_lft
	@rm -f $(OBJS_1)
	@rm -f $(OBJS_2)
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
