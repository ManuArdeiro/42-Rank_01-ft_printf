/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:47:44 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/08 18:59:22 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
		// si es null es como str="(null)"
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
