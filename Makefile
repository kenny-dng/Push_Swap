# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chduong <chduong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 15:26:43 by chduong           #+#    #+#              #
#    Updated: 2021/11/19 15:14:23 by chduong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################
#		Programmes			#
#############################
NAME	=	push_swap

#############################
#		Compilation			#
#		& Flags				#
#############################
CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
IFLAGS	= 	-I includes
LFLAGS	=	-L $(LIBFT_DIR) -lft
DEBUG	= 	-fsanitize=address -g3

RM		= 	rm -rf

#############################
#		DIRECTORIES &		#
#		Sources Files		#
#############################
LIBFT_DIR	= libft/
LIBFT		= $(LIBFT_DIR)libft.a

SRC_DIR = 	srcs/
SRC		=	push.c			swap.c			rotate.c		rev_rotate.c\
			index_stack.c	parser.c		print_stack.c	main.c\
			algo_3.c		algo_6.c		utils.c			find_serie.c

OBJ_DIR = obj/
OBJ 	:= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

#############################
#		MAKE	RULES		#
#############################
$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(DEBUG) -o $(NAME) $(OBJ) $(LFLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)
	make -C $(LIBFT_DIR) clean

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p ./obj
	
all:	$(NAME) bonus

bonus :	

clean:
	$(RM) $(OBJ_DIR)
	
fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
