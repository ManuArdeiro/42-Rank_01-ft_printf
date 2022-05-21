/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:48:12 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/21 19:27:58 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_var_print_nbr_right(int j, int *sol, t_options *flags)
{
	int		k;

	k = ft_printf_itoa_len(j);
	if (j == 0 && flags->precision == 0 && flags->point == 1)
	{
		while (k++ < flags->width)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	k = ft_printf_itoa_len(j);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (flags->plus == 1 && j > 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && j > 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	else if (j < 0)
		*sol = *sol + ft_printf_write_char('-', 1);
	k++;
	if (flags->plus == 0 && flags->space == 0 && j >=0)
		k--;
	ft_printf_write_itoa(j, sol, flags);
	while (k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
}

void	ft_var_print_nbr_left(int j, int *sol, t_options *flags)
{
	int		k;

	k = 0;
	if (j == 0 && flags->precision == 0 && flags->point == 1)
	{
		while (k++ < flags->width)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	k = ft_printf_itoa_len(j) + 1;
	if (flags->plus == 0 && flags->space == 0 && j >= 0)
		k--;		
	while (k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (flags->plus == 1 && j >= 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && j >= 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	else if (j < 0)
		*sol = *sol + ft_printf_write_char('-', 1);
	ft_printf_write_itoa(j, sol, flags);
}

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
	k = ft_printf_itoa_unsigned_len(j) + 1;
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (flags->plus == 1 && j > 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && j > 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	if ((flags->plus == 0 && flags->space == 0) || j == 0)
		k--;
	ft_printf_write_itoa_no_sign(j, sol, flags);
	while (k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
}

void	ft_var_print_unsigned_right(unsigned int j, int *sol, t_options *flags)
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
	if ((flags->plus == 0 && flags->space == 0) || j == 0)
		k--;
	while (k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
	k = ft_printf_itoa_unsigned_len(j);
	if (flags->plus == 1 && j > 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && j > 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	ft_printf_write_itoa_no_sign(j, sol, flags);
}
