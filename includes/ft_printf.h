/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:17:39 by jolopez-          #+#    #+#             */
/*   Updated: 2022/06/18 14:50:17 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_options
{
	int	width;
	int	point;
	int	precision;
	int	zero;
	int	minus;
	int	plus;
	int	space;
	int	pad;
}			t_options;

int			ft_printf(const char *format, ...);

int			ft_var_set_length(int length, char c, int *i);
void		ft_var_set_flags(t_options *flags, char c, int *i);
void		ft_var_read_flags(char const *text, int *i, t_options *flags);

void		ft_var_print_main(char c, va_list args, int *sol, t_options *flags);
int			ft_printf_write_char(char c, int fd);

void		ft_var_print_nbr_left(int j, int *sol, t_options *flags);
void		ft_var_print_nbr_right_1(int j, int *sol, t_options *flags);
void		ft_var_print_nbr_right_2(int j, int *sol, t_options *flags, int k);

void		ft_var_print_unsigned_left(unsigned int j, int *sol,
				t_options *flags);
void		ft_var_print_unsigned_right_1(unsigned int j, int *sol,
				t_options *flags);
void		ft_var_print_unsigned_right_2(unsigned int j, int *sol,
				t_options *flags, int k);

void		ft_var_print_chr_right(int c, int *sol, t_options *flags);
void		ft_var_print_chr_left(int c, int *sol, t_options *flags);

void		ft_var_print_str_left(char *str, int *sol, t_options *flags);
void		ft_var_print_str_right_1(char *str, int *sol, t_options *flags);
void		ft_var_print_str_right_2(char *str, int *sol, int len, int j);

void		ft_var_print_pointer(void *ptr, int *sol, t_options *flags);

void		ft_var_print_hex_left_1(char c, unsigned int hex, int *sol,
				t_options *flags);
void		ft_var_print_hex_left_2(char c, unsigned int hex, int *sol,
				t_options *flags);
void		ft_var_print_hex_right_1(char c, unsigned int hex, int *sol,
				t_options *flags);
void		ft_var_print_hex_right_2(char c, unsigned int hex, int *sol,
				t_options *flags);

int			ft_printf_strlen(char *str);
int			ft_printf_itoa_len(int j);
int			ft_printf_itoa_len_hex(unsigned long int hex);
int			ft_printf_itoa_unsigned_len(unsigned int j);

void		ft_printf_write_itoa_hex(char c, unsigned long int hex, int *sol);
void		ft_printf_write_hex_l(unsigned long int hex_l, int *sol,
				char *digits);
void		ft_printf_write_hex_u(unsigned long int hex_u, int *sol,
				char *digits);

void		ft_printf_write_itoa(int j, int *sol);
void		ft_printf_write_itoa_no_sign(unsigned int j, int *sol);

t_options	*ft_printf_flags_init(t_options *flags);

int			ft_sign_change(int j, int *sol);

#endif
