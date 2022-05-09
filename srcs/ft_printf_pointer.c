/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:48:12 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/08 18:59:31 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_var_print_pointer(void *ptr, int *sol, t_options *flags)
{
	int		len;
	int		j;

	if (!ptr)
	{
		*sol = *sol + ft_printf_write_char('0', 1);
		*sol = *sol + ft_printf_write_char('x', 1);
		*sol = *sol + ft_printf_write_char('0', 1);
		return ;
	}
	len = ft_printf_itoa_len_hex((unsigned long int)ptr);
	j = 0;
	if (flags->width > len && flags->minus == 0 && flags->zero == 0)
		while (j++ < flags->width - len)
			*sol = *sol + ft_printf_write_char(' ', 1);
	if (flags->width > len && flags->minus == 0 && flags->zero == 1)
		while (j++ < flags->width - len)
			*sol = *sol + ft_printf_write_char('0', 1);
	j = 0;
	*sol = *sol + ft_printf_write_char('0', 1);
	*sol = *sol + ft_printf_write_char('x', 1);
	ft_printf_write_itoa_hex('x', (unsigned long int)ptr, sol);
}
