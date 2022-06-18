/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:48:12 by jolopez-          #+#    #+#             */
/*   Updated: 2022/06/18 14:51:53 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_var_print_pointer_null(int *sol, t_options *flags)
{
	int	i;

	i = 3;
	if (flags->minus == 1)
	{
		*sol = *sol + write(1, "0x0", 3);
		while (i++ < flags->width && flags->zero == 0)
			*sol = *sol + ft_printf_write_char(' ', 1);
		while (i++ < flags->width && flags->zero == 1)
			*sol = *sol + ft_printf_write_char('0', 1);
	}
	if (flags->minus == 0)
	{
		while (i++ < flags->width && flags->zero == 0)
			*sol = *sol + ft_printf_write_char(' ', 1);
		while (i++ < flags->width && flags->zero == 1)
			*sol = *sol + ft_printf_write_char('0', 1);
		*sol = *sol + write(1, "0x0", 3);
	}
	return ;
}

static void	ft_var_print_pointer_right(void *ptr, int *sol, t_options *flags)
{
	int		len;
	int		j;

	if (!ptr)
	{
		ft_var_print_pointer_null(sol, flags);
		return ;
	}
	len = ft_printf_itoa_len_hex((unsigned long int)ptr);
	j = 0;
	if (flags->width > len && flags->zero == 0)
		while (j++ < flags->width - len - 2)
			*sol = *sol + ft_printf_write_char(' ', 1);
	if (flags->width > len && flags->zero == 1)
		while (j++ < flags->width - len - 2)
			*sol = *sol + ft_printf_write_char('0', 1);
	*sol = *sol + ft_printf_write_char('0', 1);
	*sol = *sol + ft_printf_write_char('x', 1);
	ft_printf_write_itoa_hex('x', (unsigned long int)ptr, sol);
}

static void	ft_var_print_pointer_left(void *ptr, int *sol, t_options *flags)
{
	int	len;
	int	j;

	if (!ptr)
	{
		ft_var_print_pointer_null(sol, flags);
		return ;
	}
	*sol = *sol + ft_printf_write_char('0', 1);
	*sol = *sol + ft_printf_write_char('x', 1);
	ft_printf_write_itoa_hex('x', (unsigned long int)ptr, sol);
	len = ft_printf_itoa_len_hex((unsigned long int)ptr);
	j = 0;
	if (flags->width > len && flags->zero == 0)
		while (j++ < flags->width - len - 2)
			*sol = *sol + ft_printf_write_char(' ', 1);
	if (flags->width > len && flags->zero == 1)
		while (j++ < flags->width - len - 2)
			*sol = *sol + ft_printf_write_char('0', 1);
}

void	ft_var_print_pointer(void *ptr, int *sol, t_options *flags)
{
	if (flags->minus == 1)
		ft_var_print_pointer_left(ptr, sol, flags);
	if (flags->minus == 0)
		ft_var_print_pointer_right(ptr, sol, flags);
}
