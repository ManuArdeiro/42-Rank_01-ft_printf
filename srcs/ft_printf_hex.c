/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:47:44 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/24 21:28:09 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_var_print_hex_left_1(char c, unsigned int hex, int *sol,
		t_options *flags)
{
	int	k;

	k = 0;
	if (hex == 0 && flags->precision == 0 && flags->point == 1)
	{
		while (k++ < flags->width)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	ft_var_print_hex_left_2(c, hex, sol, flags);
}

void	ft_var_print_hex_left_2(char c, unsigned int hex, int *sol,
		t_options *flags)
{
	int	k;

	k = ft_printf_itoa_len_hex(hex);
	if (flags->plus == 1)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1)
		*sol = *sol + ft_printf_write_char(' ', 1);
	if (flags->pad == 1 && hex != 0)
	{
		*sol = *sol + ft_printf_write_char('0', 1);
		*sol = *sol + ft_printf_write_char(c, 1);
	}
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (flags->plus == 1 || flags->space == 1)
		k++;
	ft_printf_write_itoa_hex(c, hex, sol);
	while (k++ <= flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ <= flags->width + 1 && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
}

void	ft_var_print_hex_right_1(char c, unsigned int hex, int *sol,
		t_options *flags)
{
	int	k;

	k = 0;
	if (hex == 0 && flags->precision == 0 && flags->point == 1)
	{
		while (k++ < flags->width)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	ft_var_print_hex_right_2(c, hex, sol, flags);
}

void	ft_var_print_hex_right_2(char c, unsigned int hex, int *sol,
		t_options *flags)
{	
	int	k;

	if (flags->plus == 1 || flags->space == 1)
		k = 1;
	k = k + ft_printf_itoa_len_hex((unsigned int)hex);
	if (flags->precision > ft_printf_itoa_len_hex(hex))
		flags->width = flags->width - flags->precision + k;
	while (k++ < flags->width && (flags->zero == 0 || flags->point == 1))
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ <= flags->width && flags->zero == 1 && flags->point == 0)
		*sol = *sol + ft_printf_write_char('0', 1);
	k = ft_printf_itoa_len_hex(hex);
	if (flags->plus == 1 || flags->space == 1)
		k = k + 1;
	if (flags->plus == 1)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1)
		*sol = *sol + ft_printf_write_char(' ', 1);
	if (flags->pad == 1 && hex != 0)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (flags->pad == 1 && hex != 0)
		*sol = *sol + ft_printf_write_char(c, 1);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	ft_printf_write_itoa_hex(c, hex, sol);
}
