# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 21:33:28 by jolopez-          #+#    #+#              #
#    Updated: 2022/04/23 17:19:55 by jolopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRCS 		= srcs/ft_printf.c \
			srcs/ft_printf_utils.c \
			srcs/ft_printf_var_1.c \
			srcs/ft_printf_var_2.c

OBJS		= $(INC:.c=.o)

INC 		= includes/

CC = 		gcc -c

CFLAGS = 	-Wall -Werror -Wextra

all: $(NAME)

$(NAME):	$(OBJS)
			@echo "Creating library..."
			$(CC) $(CFLAGS) $(OBJS) $(INC)
			@ar -rcs $(NAME) $(OBJS) $(INC)

clean:
			@echo "\033[33mCleaning objects...\033[0m"
			@/bin/rm -rf $(OBJ)

fclean: 	clean
			@echo "\033[33mCleaning objects and library...\033[0m"
			@/bin/rm -rf $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re test
