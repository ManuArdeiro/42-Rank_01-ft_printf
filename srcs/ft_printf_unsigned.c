/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:48:12 by jolopez-          #+#    #+#             */
/*   Updated: 2022/06/18 14:52:22 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_var_print_unsigned_left(unsigned int j, int *sol, t_options *flags)
{
	int		k;

	k = 0;
	if (j == 0 && flags->precision == 0 && flags->point == 1)
	{
		while (k++ < flags->width)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	k = ft_printf_itoa_unsigned_len(j);
	if (flags->plus == 1)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	k--;
	if (flags->plus == 1 || flags->space == 1)
		k--;
	ft_printf_write_itoa_no_sign(j, sol);
	while (k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	k--;
	while (k++ < flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
}

void	ft_var_print_unsigned_right_1(unsigned int j, int *sol,
		t_options *flags)
{
	int	k;

	k = 0;
	if (j == 0 && flags->precision == 0 && flags->point == 1)
	{
		while (k++ < flags->width)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	k = ft_printf_itoa_unsigned_len(j) + 1;
	if (flags->plus == 1 || flags->space == 1)
		k--;
	if (flags->precision > ft_printf_itoa_unsigned_len(j))
		flags->width = flags->width - flags->precision + k - 1;
	while (k++ <= flags->width && (flags->zero == 0 || flags->point == 1))
		*sol = *sol + ft_printf_write_char(' ', 1);
	k--;
	ft_var_print_unsigned_right_2(j, sol, flags, k);
}

void	ft_var_print_unsigned_right_2(unsigned int j, int *sol,
		t_options *flags, int k)
{
	while (k++ <= flags->width && flags->point == 0 && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
	k = ft_printf_itoa_unsigned_len(j) + 1;
	if (flags->plus == 1 || flags->space == 1)
		k--;
	if (flags->plus == 1)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ <= flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	ft_printf_write_itoa_no_sign(j, sol);
}
