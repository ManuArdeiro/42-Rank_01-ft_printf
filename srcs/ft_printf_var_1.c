/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:47:44 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/26 19:05:58 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_var_print_main(char c, va_list args, int *sol, t_options *flags)
{
	if (c == 'c')
	{
		ft_printf_write_char(va_args(args, char), 1);
		*sol = *sol + 1;
	}
	if (c == 's' && flags->minus == 1)
		ft_var_print_str_left(va_args(args, char *), sol, flags);
	if (c == 's' && flags->minus == 0)
		ft_var_print_str_right(va_args(args, char *), sol, flags);
	if (c == 'p')
		ft_var_print_pointer(va_args(args, void *), sol, flags);
	if ((c == 'd' || c == 'i') && flags->minus == 1)
		ft_var_print_nbr_left(va_args(args, int), sol, flags);
	if ((c == 'd' || c == 'i') && flags->minus == 0)
		ft_var_print_nbr_right(va_args(args, int), sol, flags);
	if (c == 'u' && flags->minus == 1)
		ft_var_print_unsigned_left(va_args(args, unsigned int), sol, flags);
	if (c == 'u' && flags->minus == 0)
		ft_var_print_unsigned_right(va_args(args, unsigned int), sol, flags);
	if (c == 'x' || c == 'X')
		ft_var_print_hex(c, va_args(args, unsigned long int), sol, flags);
	if (*sol == -1)
		return ;
}

void	ft_var_print_str_left(char *str, int *sol, t_options *flags)
{
	int	len;
	int	j;

	j = 0;
	len = ft_printf_strlen(str);
	if (flags->precision < len)
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
	len = ft_printf_strlen(str);
	if (flags->precision < len)
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
		*sol = *sol + ft_printf_write_char(str[j++], 1);
		j++;
	}
}

void	ft_var_print_pointer(void *ptr, int *sol, t_options *flags)
{
	char	*str;
	int		len;
	int		j;

	str = *ptr;
	len = ft_printf_strlen(str);
	j = 0;
	if (flags->width > len && flags->minus == 0 && flags->zero == 0)
		while (j < flags->width - len)
			*sol = *sol + ft_printf_write_char(' ', 1);
	if (flags->width > len && flags->minus == 0 && flags->zero == 1)
		while (j < flags->width - len)
			*sol = *sol + ft_printf_write_char('0', 1);
	j = 0;
	if (flags->width <= len)
		while (str[j])
			*sol = *sol + ft_printf_write_char(str[j++], 1);
	if (flags->width > len && flags->minus == 1 && flags->zero == 0)
		while (j < flags->width - len)
			*sol = *sol + ft_printf_write_char(' ', 1);
	if (flags->width > len && flags->minus == 1 && flags->zero == 1)
		while (j < flags->width - len)
			*sol = *sol + ft_printf_write_char('0', 1);
}
