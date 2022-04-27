/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:17:39 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/26 19:31:50 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_options
{
	int	width;
	int	precision;
	int	zero;
	int	minus;
	int	plus;
	int	space;
	int	pad;
}				t_options;

int			ft_printf(const char *format, ...);

int			ft_printf_write_char(char c, int fd);
t_options	*ft_printf_flags_init(t_options *flags);
int			ft_printf_strlen(char *str);
int			ft_printf_itoa_len(int j);
void		ft_print_write_itoa(int j, int *sol, t_options *flags);

void		ft_var_print_main(char c, va_list args, int *sol, t_options *flags);
void		ft_var_print_str_left(char *str, int *sol, t_options *flags);
void		ft_var_print_str_right(char *str, int *sol, t_options *flags);
void		ft_var_print_pointer(void *ptr, int *sol, t_options *flags);

void		ft_var_print_nbr_left(int j, int *sol, t_options *flags);
void		ft_var_print_nbr_right(int j, int *sol, t_options *flags);
void		ft_var_print_unsigned_left(unsigned int j, int *sol, t_options *flags);
void		ft_var_print_hex_right(char c, unsigned long int hex, int *sol,
				t_options *flags);

#endif
