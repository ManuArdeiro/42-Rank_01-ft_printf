/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:17:39 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/01 18:48:57 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
}			t_options;

// ft_printf.c
int			ft_printf(const char *format, ...);

// ft_printf_utils_1.c
int			ft_printf_write_char(char c, int fd);
t_options	*ft_printf_flags_init(t_options *flags);
int			ft_printf_strlen(char *str);
int			ft_printf_itoa_len(int j);
void		ft_printf_write_itoa(int j, int *sol);

// ft_printf_utils_2.c
int			ft_printf_itoa_len_hex(unsigned long int hex);
void		ft_printf_write_itoa_hex(char c, unsigned long int hex, int *sol);
void		ft_printf_write_hex(unsigned long int hex,int *sol, char *digits);
void		ft_printf_write_HEX(unsigned long int HEX,int *sol, char *digits);

//ft_printf_utils_3.c
int 		ft_printf_itoa_len_octal(unsigned int octal);
void    	ft_printf_write_octal(unsigned int octal, int *sol);

// ft_printf_var_1.c
void		ft_var_print_main(char c, va_list args, int *sol, t_options *flags);
void		ft_var_print_str_left(char *str, int *sol, t_options *flags);
void		ft_var_print_str_right(char *str, int *sol, t_options *flags);
void		ft_var_print_hex_left(char c, unsigned long int hex, int *sol,
				t_options *flags);
void		ft_var_print_hex_right(char c, unsigned long int hex, int *sol,
				t_options *flags);

// ft_printf_var_2.c
void		ft_var_print_nbr_left(int j, int *sol, t_options *flags);
void		ft_var_print_nbr_right(int j, int *sol, t_options *flags);
void		ft_var_print_unsigned_left(unsigned int j, int *sol,
				t_options *flags);
void		ft_var_print_unsigned_right(unsigned int j, int *sol,
				t_options *flags);
void		ft_var_print_pointer(void *ptr, int *sol, t_options *flags);

// ft_printf_var_3.c
void		ft_var_print_octal(unsigned int octal, int *sol, t_options *flags);
void		ft_var_print_octal_left(unsigned int octal, int *sol,
				t_options *flags);
void		ft_var_print_octal_right(unsigned int octal, int *sol, 
				t_options *flags);

#endif
