# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 21:33:28 by jolopez-          #+#    #+#              #
#    Updated: 2022/05/01 19:57:57 by jolopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRCS 		= srcs/ft_printf_utils_1.c \
			srcs/ft_printf_utils_2.c \
			srcs/ft_printf_utils_3.c \
			srcs/ft_printf_var_1.c \
			srcs/ft_printf_var_2.c \
			srcs/ft_printf_var_3.c

MAIN		= srcs/ft_printf.c

BONUS		= srcs/ft_printf_bonus.c

OBJS		= $(SRCS:.c=.o)

MAIN_OBJS	= $(MAIN:.c=.o)

BONUS_OBJS	= $(SRCS:.c=.o)

INC 		= includes/

CC = 		gcc

CFLAGS = 	-Wall -Werror -Wextra -I$(INC)

all: $(NAME)

$(NAME):	$(OBJS)$(MAIN_OBJS)
			@echo "$(GREEN)Creating library...$(WHITE)"
			ar -rcs $(NAME) $(OBJS) $(MAIN_OBJS)
			$(CC) $(CFLAGS) $(OBJS) main.c
			@echo "$(DARK_GRAY)Done..."

bonus:		mclean
			$(OBJS)$(BONUS_OBJS)
			@echo "$(GREEN)Creating bonus library...$(WHITE)"
			ar -rcs $(NAME) $(OBJS) &(BONUS_OBJS)
			$(CC) $(CFLAGS) $(OBJS) main.c
			@echo "$(DARK_GRAY)Done..."			

clean:
			@echo "$(LIGHT_RED)Cleaning objects...$(WHITE)"
			/bin/rm -rf $(OBJS) $(MAIN:OBJS) $(BONUS_OBJS)
			/bin/rm -rf a.out

mclean:		@echo "$(LIGHT_RED)Cleaning main printf...$(WHITE)"
			/bin/rm -rf $(MAIN_OBJS)
			/bin/rm -rf a.out

fclean: 	clean
			@echo "$(YELLOW)Cleaning objects and library...$(WHITE)"
			/bin/rm -rf $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re test mclean bonus

# COLORS
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
LIGHT_GRAY	= \033[0;37m
DARK_GRAY	= \033[0;90m
LIGHT_RED	= \033[0;91m
WHITE		= \033[0;97m

#SETS
BOLD		= \e[0;1m
UNDERLINED	= \e[0;4m
BLINK		= \e[0;5m
