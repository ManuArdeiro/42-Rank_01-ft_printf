/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:17:39 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/08 17:17:31 by jolopez-         ###   ########.fr       */
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
	int	precision;
	int	zero;
	int	minus;
	int	plus;
	int	space;
	int	pad;
}			t_options;

// ft_printf.c
int			ft_printf(const char *format, ...);

// ft_printf_manage_flags.c

int			ft_var_set_length(int length, char c, int *i);
void			ft_var_set_flags(t_options *flags, char c, int *i);
void			ft_var_read_flags(char const *text, int *i, t_options *flags);

// ft_printf_select_var.c

void		ft_var_print_main(char c, va_list args, int *sol, t_options *flags);
int		ft_printf_write_char(char c, int fd);

// ft_printf_numbers.c

void		ft_var_print_nbr_left(int j, int *sol, t_options *flags);
void		ft_var_print_nbr_right(int j, int *sol, t_options *flags);
void		ft_var_print_unsigned_left(unsigned int j, int *sol,
				t_options *flags);
void		ft_var_print_unsigned_right(unsigned int j, int *sol,
				t_options *flags);

// ft_printf_chars.c

void	ft_var_print_chr_right(int c, int *sol, t_options *flags)
void	ft_var_print_chr_left(int c, int *sol, t_options *flags)

//ft_printf_strings.c
	
void		ft_var_print_str_left(char *str, int *sol, t_options *flags);
void		ft_var_print_str_right(char *str, int *sol, t_options *flags);

// ft_printf_pointer.c

void		ft_var_print_pointer(void *ptr, int *sol, t_options *flags);

// ft_printf_hex.c

void		ft_var_print_hex_left(char c, unsigned int hex, int *sol,
				t_options *flags);
void		ft_var_print_hex_right(char c, unsigned int hex, int *sol,
				t_options *flags);

// ft_printf_utils_len.c
int			ft_printf_strlen(char *str);
int			ft_printf_strlen(char *str);
int			ft_printf_itoa_unsigned_len(unsigned int j);
int			ft_printf_itoa_len(int j);

// ft_printf_utils_write_hex.c
void		ft_printf_write_itoa_hex(char c, unsigned long int hex, int *sol);
void		ft_printf_write_hex_l(unsigned long int hex_l, int *sol,
				char *digits);
void		ft_printf_write_hex_u(unsigned long int hex_u, int *sol,
				char *digits);

// ft_printf_utils_write_itoa.c

void		ft_printf_write_itoa(int j, int *sol);
void		ft_printf_write_itoa_unsigned(unsigned int j, int *sol);

// ft_printf_utils_flags_init.c
t_options	*ft_printf_flags_init(t_options *flags);


//ft_printf_utils_sign_change.c
int 		ft_sign_change(int j, int *sol);


#endif
