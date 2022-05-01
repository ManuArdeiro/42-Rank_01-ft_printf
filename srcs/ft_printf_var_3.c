/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:46:12 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/01 18:34:19 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_var_print_octal(unsigned int octal, int *sol, t_options *flags)
{
	if (flags->minus == 1)
		ft_var_print_octal_left(octal, sol, flags);
	if (flags->minus == 0)
		ft_var_print_octal_right(octal, sol, flags);
}

void	ft_var_print_octal_left(unsigned int octal, int *sol, t_options *flags)
{
	int k;
	
	k = 0;
	if (octal == 0 && flags->precision == 0)
	{
		while (k++ < flags->width && flags->width != -1)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	k = ft_printf_itoa_len_octal(octal);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (flags->plus == 1 && octal > 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && octal > 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	ft_printf_write_octal(octal, sol);
	if (octal > 0 && flags->plus == 0 && flags->space == 0)
		flags->precision = flags->precision - 1;
	if (flags->precision >= 0)
		k = flags->precision + 1;
	while (k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
}

void	ft_var_print_octal_right(unsigned int octal, int *sol, t_options *flags)
{
	int	k;

	k = 0;
	if (octal == 0 && flags->precision == 0)
	{
		while (k++ < flags->width && flags->width != -1)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	if (octal > 0 && flags->plus == 0 && flags->space == 0)
		flags->precision = flags->precision - 1;
	if (flags->precision >= 0)
		k = flags->precision + 1;
	while (k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
	k = ft_printf_itoa_len_octal(octal);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (flags->plus == 1 && octal > 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && octal > 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	ft_printf_write_octal(octal, sol);
}
