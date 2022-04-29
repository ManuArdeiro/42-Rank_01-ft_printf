/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:48:12 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/29 21:49:19 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_var_print_nbr_left(int j, int *sol, t_options *flags)
{
	int		k;

	k = 0;
	if (j == 0 && flags->precision == 0)
	{
		while (k++ < flags->width)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	if (j > 0 && flags->plus == 0 && flags->space == 0)
		flags->precision = flags->precision + 1;
	k = ft_printf_itoa_len(j);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (flags->plus == 1 && j > 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && j > 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	else if (j < 0)
		*sol = *sol + ft_printf_write_char('-', 1);
	ft_printf_write_itoa(j, sol);
	while (k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
}

void	ft_var_print_nbr_right(int j, int *sol, t_options *flags)
{
	int		k;

	k = 0;
	if (j == 0 && flags->precision == 0)
	{
		while (k++ < flags->width)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	if (j > 0 && flags->plus == 0 && flags->space == 0)
		flags->precision = flags->precision - 1;
	k = flags->precision + 1;
	while (k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
	k = ft_printf_itoa_len(j);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (flags->plus == 1 && j >= 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && j >= 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	else if (j < 0)
		*sol = *sol + ft_printf_write_char('-', 1);
	ft_printf_write_itoa(j, sol);
}

void	ft_var_print_unsigned_left(unsigned int j, int *sol, t_options *flags)
{
	int		k;

	k = 0;
	if (j == 0 && flags->precision == 0)
	{
		while (k++ < flags->width)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	if (flags->plus == 0 && flags->space == 0)
		flags->precision = flags->precision + 1;
	k = ft_printf_itoa_len(j);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (flags->plus == 1 && j > 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && j > 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	ft_printf_write_itoa(j, sol);
	while (k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
}

void	ft_var_print_unsigned_right(unsigned int j, int *sol, t_options *flags)
{
	int	k;

	k = 0;
	if (j == 0 && flags->precision == 0)
	{
		while (k++ < flags->width)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	if (j > 0 && flags->plus == 0 && flags->space == 0)
		flags->precision = flags->precision - 1;
	k = flags->precision + 1;
	while (k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ < flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
	k = ft_printf_itoa_len(j);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (flags->plus == 1 && j > 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && j > 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	ft_printf_write_itoa(j, sol);
}

void	ft_var_print_pointer(void *ptr, int *sol, t_options *flags)
{
	int		len;
	int		j;

	len = ft_printf_itoa_len_hex((unsigned long)ptr);
	printf("ptr = %p len = %d", ptr, len);
	j = 0;
	if (flags->width > len && flags->minus == 0 && flags->zero == 0)
		while (j < flags->width - len)
		{
			*sol = *sol + ft_printf_write_char(' ', 1);
			j++;
		}
	if (flags->width > len && flags->minus == 0 && flags->zero == 1)
		while (j < flags->width - len)
		{
			*sol = *sol + ft_printf_write_char('0', 1);
			j++;
		}
	j = 0;
	ft_printf_write_itoa_hex('x', (int)ptr, sol);
}
