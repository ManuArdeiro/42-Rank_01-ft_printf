/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:47:44 by jolopez-          #+#    #+#             */
/*   Updated: 2022/06/18 14:52:12 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_write_null(int *sol, t_options *flags)
{
	int		i;
	char	*null;

	i = 0;
	null = "(null)";
	if (flags->width > 6 && flags->zero == 1)
		while (i++ < flags->width - 6)
			*sol = *sol + ft_printf_write_char('0', 1);
	i = 0;
	if (flags->width > 6 && flags->zero == 0)
		while (i++ < flags->width - 6)
			*sol = *sol + ft_printf_write_char(' ', 1);
	i = 0;
	if (flags->point == 1)
		while (i < flags->precision && null[i] != '\0')
			*sol = *sol + ft_printf_write_char(null[i++], 1);
	i = 0;
	if (flags->point == 0)
		while (null[i] != '\0')
			*sol = *sol + ft_printf_write_char(null[i++], 1);
	i = 0;
	if (flags->width > 6 && flags->minus == 0 && flags->zero == 1)
		while (i++ < flags->width - 6)
			*sol = *sol + ft_printf_write_char('0', 1);
}

void	ft_var_print_str_left(char *str, int *sol, t_options *flags)
{
	int	len;
	int	j;

	j = 0;
	if (!str)
	{
		ft_write_null(sol, flags);
		return ;
	}
	len = ft_printf_strlen(str);
	if (flags->precision < len && flags->point == 1)
		len = flags->precision;
	while (j < len)
		*sol = *sol + ft_printf_write_char(str[j++], 1);
	if (flags->width > len)
	{
		if (flags->zero == 0)
			while (j++ < flags->width)
				*sol = *sol + ft_printf_write_char(' ', 1);
		j = 0;
		if (flags->zero == 1)
			while (j++ < flags->width)
				*sol = *sol + ft_printf_write_char('0', 1);
	}
}

void	ft_var_print_str_right_1(char *str, int *sol, t_options *flags)
{
	int	len;
	int	j;

	j = 0;
	if (!str)
	{
		ft_write_null(sol, flags);
		return ;
	}
	len = ft_printf_strlen(str);
	if (flags->precision < len && flags->point == 1)
		len = flags->precision;
	if (flags->width > len)
	{
		if (flags->zero == 0)
			while (j++ < flags->width - len)
				*sol = *sol + ft_printf_write_char(' ', 1);
		j = 0;
		if (flags->zero == 1)
			while (j++ < (flags->width) - len)
				*sol = *sol + ft_printf_write_char('0', 1);
		j = 0;
	}
	ft_var_print_str_right_2(str, sol, len, j);
}

void	ft_var_print_str_right_2(char *str, int *sol, int len, int j)
{
	while (j < len)
	{
		*sol = *sol + ft_printf_write_char(str[j], 1);
		j++;
	}
}
