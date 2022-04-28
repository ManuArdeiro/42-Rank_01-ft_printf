# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 21:33:28 by jolopez-          #+#    #+#              #
#    Updated: 2022/04/26 18:19:25 by jolopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRCS 		= srcs/ft_printf.c \
			srcs/ft_printf_utils_1.c \
			srcs/ft_printf_utils_2.c \
			srcs/ft_printf_var_1.c \
			srcs/ft_printf_var_2.c

OBJS		= $(SRCS:.c=.o)

INC 		= includes/

CC = 		gcc

CFLAGS = 	-Wall -Werror -Wextra -I$(INC)

all: $(NAME)

$(NAME):	$(OBJS)
			@echo "Creating library..."
			ar -rcs $(NAME) $(OBJS)

clean:
			@echo "\033[33mCleaning objects...\033[0m"
			/bin/rm -rf $(OBJ)

fclean: 	clean
			@echo "\033[33mCleaning objects and library...\033[0m"
			/bin/rm -rf $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re test
