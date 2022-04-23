/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:17:39 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/23 17:15:18 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FT_PRINTF_H
# define LIB_FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef struct		s_options
{                        
      int	width;
      int	precision;
      int	zero;
      int	minus;
      int	plus;
      int	space;
      int	pad;
}			t_options;

int					ft_printf(const char *format, ...);
static void			ft_var_print(char const *text,va_list args);
static void			ft_var_set_flags(char c);
static void			ft_var_set_length(char c);

int					ft_printf_write(char c, int fd);
t_options			ft_printf_flags_init(t_options flags);

void				ft_var_print_main(char c, va_list args);
void				ft_var_print_str(char *str, int *sol);
void				ft_var_print_pointer(void *ptr, int *sol);

void				ft_var_print_nbr(int i, int *sol);
void				ft_var_print_unsigned(unsigned int i, int *sol);
void				ft_var_print_hex(char c, unsigned long int hex, int *sol);

#endif
