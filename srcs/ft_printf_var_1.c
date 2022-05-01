/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:47:44 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/01 20:32:15 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_var_print_main(char c, va_list args, int *sol, t_options *flags)
{
	if (c == 'c')
		*sol = *sol + ft_printf_write_char(va_arg(args, int), 1);
	if (c == 's' && flags->minus == 1)
		ft_var_print_str_left(va_arg(args, char *), sol, flags);
	if (c == 's' && flags->minus == 0)
		ft_var_print_str_right(va_arg(args, char *), sol, flags);
	if (c == 'p')
		ft_var_print_pointer(va_arg(args, void *), sol, flags);
	if ((c == 'd' || c == 'i') && flags->minus == 1)
		ft_var_print_nbr_left(va_arg(args, int), sol, flags);
	if ((c == 'd' || c == 'i') && flags->minus == 0)
		ft_var_print_nbr_right(va_arg(args, int), sol, flags);
	if (c == 'u' && flags->minus == 1)
		ft_var_print_unsigned_left(va_arg(args, unsigned int), sol, flags);
	if (c == 'u' && flags->minus == 0)
		ft_var_print_unsigned_right(va_arg(args, unsigned int), sol, flags);
	if ((c == 'x' || c == 'X') && flags->minus == 1)
		ft_var_print_hex_left(c, va_arg(args, unsigned long int), sol, flags);
	if ((c == 'x' || c == 'X') && flags->minus == 0)
		ft_var_print_hex_right(c, va_arg(args, unsigned long int), sol, flags);
	if (c == 'o')
		ft_var_print_octal(va_arg(args, unsigned int), sol, flags);
	if (*sol == -1)
		return ;
}

void	ft_var_print_str_left(char *str, int *sol, t_options *flags)
{
	int	len;
	int	j;

	j = 0;
	if (!str)
	{
		write(1, "(NULL)", 6);
		return ;
	}
	len = ft_printf_strlen(str);
	if (flags->precision < len && flags->precision != -1)
		len = flags->precision;
	while (str[j] && j < len)
	{
		*sol = *sol + ft_printf_write_char(str[j], 1);
		j++;
	}
	if (flags->width > len)
	{
		if (flags->zero == 0)
			while (j++ < flags->width)
				*sol = *sol + ft_printf_write_char(' ', 1);
		if (flags->zero == 1)
			while (j++ < flags->width)
				*sol = *sol + ft_printf_write_char('0', 1);
	}
}

void	ft_var_print_str_right(char *str, int *sol, t_options *flags)
{
	int	len;
	int	j;

	j = 0;
	if (!str)
	{
		*sol = *sol + ft_printf_write_char('(', 1);
		*sol = *sol + ft_printf_write_char('n', 1);
		*sol = *sol + ft_printf_write_char('u', 1);
		*sol = *sol + ft_printf_write_char('l', 1);
		*sol = *sol + ft_printf_write_char('l', 1);
		*sol = *sol + ft_printf_write_char(')', 1);
		return ;
	}
	len = ft_printf_strlen(str);
	len = ft_printf_strlen(str);
	if (flags->precision < len && flags->precision != -1)
		len = flags->precision;
	if (flags->width > len)
	{
		if (flags->zero == 0)
			while (j++ < flags->width - len)
				*sol = *sol + ft_printf_write_char(' ', 1);
		if (flags->zero == 1)
			while (j++ < (flags->width) - len)
				*sol = *sol + ft_printf_write_char('0', 1);
	}
	j = 0;
	while (str[j] && j < len)
	{
		*sol = *sol + ft_printf_write_char(str[j], 1);
		j++;
	}
}

void	ft_var_print_hex_left(char c, unsigned long int hex, int *sol,
	   t_options *flags)
{
	int	k;

	k = 0;
	if (hex == 0 && flags->precision == 0)
	{
		while (k++ < flags->width && flags->width != -1)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	k = ft_printf_itoa_len_hex(hex);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (flags->plus == 1 && hex > 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && hex > 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	ft_printf_write_itoa_hex_l(c, hex, sol);
	if (hex > 0 && flags->plus == 0 && flags->space == 0)
		flags->precision = flags->precision - 1;
	if (flags->precision >= 0)
		k = flags->precision + 1;
	while (k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
}

void	ft_var_print_hex_right(char c, unsigned long int hex, int *sol,
		t_options *flags)
{
	int	k;

	k = 0;
	if (hex == 0 && flags->precision == 0)
	{
		while (k++ < flags->width && flags->width != -1)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	if (hex > 0 && flags->plus == 0 && flags->space == 0)
		flags->precision = flags->precision - 1;
	if (flags->precision >= 0)
		k = flags->precision + 1;
	while (k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
	k = ft_printf_itoa_len_hex(hex);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (flags->plus == 1 && hex > 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && hex > 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	ft_printf_write_itoa_hex(c, hex, sol);
}
