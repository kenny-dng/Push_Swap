# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chduong <chduong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 15:26:43 by chduong           #+#    #+#              #
#    Updated: 2021/12/03 16:23:01 by chduong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################################
#				PROGRAMS				#
#########################################
PS			=	push_swap
CHECKER		=	checker

#########################################
#				COMMANDS				#
#########################################
CC			=	clang
MKDIR		=	mkdir -p
AR			=	ar rcs
RM			= 	rm -rf

#########################################
#			FLAGS COMPILATION			#
#########################################
CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	+=	${IFLAGS} 

IFLAGS	= 	-I includes
LFLAGS	=	-L $(LIBFT_DIR) -lft
DEBUG	= 	-fsanitize=address -g3

#########################################
#			DIRECTORIES					#
#########################################
SRC_DIR			=	srcs/
OBJ_DIR			=	obj/
PS_OBJ_DIR		=	push_swap/
CHK_OBJ_DIR		=	checker/
LIBFT_DIR		=	libft/

#########################################
#			SOURCES	FILES				#
#########################################
LIBFT			= $(LIBFT_DIR)libft.a

PS_SRC		=	main.c				algo_3.c				algo_6.c\
				algo_step1.c		algo_step2.c			algo_step3.c\
				ft_do_move.c		ft_print_stack.c		ft_index_stack.c\
				ft_checksort.c		utils.c					ft_parser.c\
				ft_push.c			ft_rotate.c				ft_rrotate.c\
				ft_swap.c

CHK_SRC		=	main.c				ft_gnl.c				ft_gnl_utils.c\
				ft_parser.c			ft_push.c				ft_rotate.c\
				ft_rrotate.c		ft_swap.c				ft_check_stack.c\
				ft_do_read.c

#########################################
#            OBJECT FILES    	        #
#########################################
PS_OBJ				=	$(PS_SRC:.c=.o)
PS_OBJ				:=	$(addprefix $(PS_OBJ_DIR), $(PS_OBJ))
PS_OBJ				:=	$(addprefix $(OBJ_DIR), $(PS_OBJ))

CHK_OBJ				=	$(CHK_SRC:.c=.o)
CHK_OBJ				:=	$(addprefix $(CHK_OBJ_DIR), $(CHK_OBJ))
CHK_OBJ				:=	$(addprefix $(OBJ_DIR), $(CHK_OBJ))

#########################################
#			MAKE	RULES				#
#########################################
$(PS): $(LIBFT) $(OBJ_DIR) $(PS_OBJ)
	$(CC) $(DEBUG) -o $@ $(PS_OBJ) $(LFLAGS)

$(CHECKER): $(LIBFT) $(OBJ_DIR) $(CHK_OBJ)
	$(CC) $(DEBUG) -o $@ $(CHK_OBJ) $(LFLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} -c -o $@ ${CFLAGS} $<

$(OBJ_DIR):
	mkdir -p ./obj
	
all:	$(PS) $(CHECKER)

bonus :	$(CHECKER)
	
clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)
	
fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(PS)
	$(RM) $(CHECKER)

re: fclean all

norm:
	@norminette ${SRC_DIR} ${INC_DIR} | grep 'Error' ; true

.PHONY: all clean fclean re
