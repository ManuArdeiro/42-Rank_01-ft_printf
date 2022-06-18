/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:48:12 by jolopez-          #+#    #+#             */
/*   Updated: 2022/06/18 14:51:45 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_precision(int j, t_options *flags)
{
	if (flags->precision > ft_printf_itoa_len(j))
		return (flags->precision);
	else
		return (ft_printf_itoa_len(j));
}

void	ft_var_print_nbr_left(int j, int *sol, t_options *flags)

{
	int		k;

	k = ft_printf_itoa_len(j);
	if (j == 0 && flags->precision == 0 && flags->point == 1)
	{
		while (k++ <= flags->width)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	if (flags->plus == 1 && j >= 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && j >= 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	else if (j < 0)
		*sol = *sol + ft_printf_write_char('-', 1);
	while (k++ < flags->precision)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (j < 0 || flags->plus == 1 || flags->space == 1)
		k++;
	ft_printf_write_itoa(j, sol);
	while (k++ <= flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (k++ <= (flags->width + 1) && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
}

void	ft_var_print_nbr_right_1(int j, int *sol, t_options *flags)
{
	int		k;

	k = 0;
	if (j == 0 && flags->precision == 0 && flags->point == 1)
	{
		while (k++ < flags->width)
			*sol = *sol + ft_printf_write_char(' ', 1);
		return ;
	}
	if (j < 0 || flags->plus == 1 || flags->space == 1)
		k = 1;
	while (ft_precision(j, flags) + k++ < flags->width && flags->zero == 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	while (ft_precision(j, flags) + k++ <= flags->width && flags->point == 1)
		*sol = *sol + ft_printf_write_char(' ', 1);
	k--;
	ft_var_print_nbr_right_2(j, sol, flags, k);
}

void	ft_var_print_nbr_right_2(int j, int *sol, t_options *flags, int k)
{
	if (flags->plus == 1 && j >= 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && j >= 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	else if (j < 0)
		*sol = *sol + ft_printf_write_char('-', 1);
	while (ft_precision(j, flags) + k++ <= flags->width && flags->zero == 1)
		*sol = *sol + ft_printf_write_char('0', 1);
	k = ft_printf_itoa_len(j);
	while (k++ < (flags->precision))
		*sol = *sol + ft_printf_write_char('0', 1);
	ft_printf_write_itoa(j, sol);
}
