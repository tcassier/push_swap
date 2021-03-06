# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 07:29:26 by tcassier          #+#    #+#              #
#    Updated: 2018/01/31 07:29:27 by tcassier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME_1 = checker
NAME_2 = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_PATH) -I$(LFT_INC_PATH)

SRC_1_PATH = ./src_checker/
SRC_2_PATH = ./src_push_swap/
SRC_3_PATH = ./src_both/
SRCS_1 = $(addprefix $(SRC_1_PATH), $(SRC_1)) $(SRCS_3)
SRCS_2 = $(addprefix $(SRC_2_PATH), $(SRC_2)) $(SRCS_3)
SRCS_3 = $(addprefix $(SRC_3_PATH), $(SRC_3))
SRC_1 = checker.c            \
		print_stack.c        \
		process_ck.c
SRC_2 = check_backstack.c    \
		check_upstack.c      \
		exec_save.c          \
		get_median.c         \
		lst_cleaner.c        \
		process_ps.c         \
		push_swap.c          \
		quick_sort.c         \
		small_sort.c
SRC_3 =	check_stack.c        \
		exec_pa.c            \
		exec_pb.c            \
		exec_ra.c            \
		exec_rb.c            \
		exec_rr.c            \
		exec_rra.c           \
		exec_rrb.c           \
		exec_rrr.c           \
		exec_sa.c            \
		exec_sb.c            \
		exec_ss.c            \
		failure.c            \
		parser.c

OBJ_PATH = ./obj/
OBJS_1 = $(addprefix $(OBJ_PATH), $(OBJ_1))
OBJS_2 = $(addprefix $(OBJ_PATH), $(OBJ_2))
OBJS_3 = $(addprefix $(OBJ_PATH), $(OBJ_3))
OBJ_1 = $(SRC_1:.c=.o)
OBJ_2 = $(SRC_2:.c=.o)
OBJ_3 = $(SRC_3:.c=.o)

INC_PATH = ./includes/
INCS_1 = $(addprefix $(INC_PATH), $(INC_1))
INCS_2 = $(addprefix $(INC_PATH), $(INC_2))
INCS_3 = $(addprefix $(INC_PATH), $(INC_3))
INC_1 = checker.h
INC_2 = push_swap.h
INC_3 = both.h

LFT_INC_PATH = $(LFT_PATH)includes/
LFT_PATH = ./libft/
LFT_FLAG = -L $(LFT_PATH) -lft

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ_PATH) $(OBJS_1) $(OBJS_3)
	@make -C $(LFT_PATH) all
	@$(CC) $(CFLAGS) -o $@ $(OBJS_1) $(OBJS_3) $(LFT_FLAG)

$(NAME_2): $(OBJ_PATH) $(OBJS_2) $(OBJS_3)
	@make -C $(LFT_PATH) all
	@$(CC) $(CFLAGS) -o $@ $(OBJS_2) $(OBJS_3) $(LFT_FLAG)

$(OBJ_PATH)%.o: $(SRC_1_PATH)%.c $(INCS_1) $(INCS_3)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(SRC_2_PATH)%.c $(INCS_2) $(INCS_3)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(SRC_3_PATH)%.c $(INCS_3)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean: clean_lft
	@rm -f $(OBJS_1)
	@rm -f $(OBJS_2)
	@rm -f $(OBJS_3)
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
