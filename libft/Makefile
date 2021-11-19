# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chduong <chduong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/22 15:57:00 by chduong           #+#    #+#              #
#    Updated: 2021/11/18 15:27:47 by chduong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libft.a

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	ft_atol.c		ft_ilen.c		ft_isdigit.c\
			ft_putchar_fd.c ft_putnbr_fd.c	ft_putstr_fd.c\
			ft_lstnew.c		ft_lstsize.c	ft_lstadd_front.c\
			ft_lstlast.c	ft_lstdelone.c	ft_lstadd_back.c\
			ft_lstclear.c	ft_strlen.c		

OBJ		=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	ar -rcs $(NAME) $(OBJ)
	

all:		$(NAME)

clean:
	$(RM) $(OBJ)

fclean: 
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
