/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:47:44 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/08 18:59:22 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_var_print_hex_left(char c, unsigned int hex, int *sol,
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
	printf("\nk = ft_printf_itoa_len_hex(hex) = %d\n", k);
	printf("\nflags->width = %d\n", flags->width);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (flags->plus == 1 && hex > 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && hex > 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	ft_printf_write_itoa_hex(c, hex, sol);
	if (hex > 0 && flags->plus == 0 && flags->space == 0)
		flags->precision = flags->precision - 1;
	if (flags->precision >= 0)
		k = flags->precision + 1;
	while (k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
}

void	ft_var_print_hex_right(char c, unsigned int hex, int *sol,
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