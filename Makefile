# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 21:33:28 by jolopez-          #+#    #+#              #
#    Updated: 2022/05/21 19:49:42 by jolopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRCS 		= srcs/ft_printf_manage_flags.c \
			srcs/ft_printf_select_var.c \
			srcs/ft_printf_numbers.c \
			srcs/ft_printf_chars.c \
			srcs/ft_printf_strings.c \
		   	srcs/ft_printf_pointer.c \
			srcs/ft_printf_hex.c \
			srcs/ft_printf_utils_len.c \
			srcs/ft_printf_utils_write_hex.c \
			srcs/ft_printf_utils_write_itoa.c \
			srcs/ft_printf_utils_flags_init.c \
			srcs/ft_printf_utils_sign_change.c

MAIN		= srcs/ft_printf.c

BONUS		= srcs/ft_printf_bonus.c

OBJS		= $(SRCS:.c=.o)

MAIN_OBJS	= $(MAIN:.c=.o)

BONUS_OBJS	= $(BONUS:.c=.o)

INC 		= includes/

CC = 		gcc

CFLAGS = 	-Wall -Werror -Wextra -I$(INC) -g3

all: $(NAME)

$(NAME):	$(OBJS) $(MAIN_OBJS)
			@echo "$(YELLOW) Creating library... $(WHITE)"
			ar -rcs $(NAME) $(OBJS) $(MAIN_OBJS)
			
bonus:		fclean $(OBJS) $(BONUS_OBJS)
			@echo "$(YELLOW) Creating bonus library... $(WHITE)"
			ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) main.c
			@echo "$(GREEN) Done..."			

clean:
			@echo "$(LIGHT_RED) Cleaning objects... $(WHITE)"
			/bin/rm -rf $(OBJS) $(MAIN:OBJS) $(BONUS_OBJS)

mclean:		
			@echo "$(LIGHT_RED) Cleaning main printf... $(WHITE)"
			/bin/rm -rf $(MAIN_OBJS)

fclean: 	clean mclean
			@echo "$(LIGHT_RED) Cleaning objects and library... $(WHITE)"
			/bin/rm -rf $(NAME)

test:		$(NAME)
			$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJS) main.c
			@echo "$(MAGENTA) Done..."
			./a.out
			make fclean
			rm a.out

bonus_test:	bonus
			$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) main.c
			@echo "$(DARK_GRAY) Done..."
			./a.out
			make fclean
#			rm a.out

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
