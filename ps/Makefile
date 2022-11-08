# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greita <greita@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 08:39:44 by greita            #+#    #+#              #
#    Updated: 2022/02/09 12:07:33 by greita           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		push_swap

NAME_B =	checker

SRC =		input_checks.c getargs.c getsorted_args.c operrr.c opers.c \
			ps_utils.c sort_utils.c sort.c sort345.c push_swap.c

SRC_B =		input_checks.c getargs.c getsorted_args.c operrr.c opers.c \
			ps_utils.c sort_utils.c sort.c sort345.c checker.c

OBJ = 		$(SRC:.c=.o)

OBJ_B = 	$(SRC_B:.c=.o)

CC =		gcc

FLAGS =		-Wall -Wextra -Werror

D_FILES =	$(SRC:.c=.d)

D_FILES_B =	$(SRC_B:.c=.d)

%.o :		%.c
	$(CC) $(FLAGS) -c $< -o $@ -MMD

all :		$(NAME)

bonus:		$(NAME_B)

-include	$(D_FILES) $(D_FILES_B)

$(NAME) :	$(OBJ)
	make all -C ./libft
	$(CC) $(FLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

$(NAME_B) :	$(OBJ_B)
	make all -C ./libft
	$(CC) $(FLAGS) $(OBJ_B) ./libft/libft.a -o $(NAME_B)

clean :
	make clean -C ./libft
	rm -f $(OBJ) $(OBJ_B) $(D_FILES) $(D_FILES_B)

fclean :	clean
	rm -f ./libft/libft.a
	rm -f $(NAME)
	rm -f $(NAME_B)

re :		fclean all

rebonus :	fclean bonus

.PHONY :	all clean fclean re rebonus bonus
