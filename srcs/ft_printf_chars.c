/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:33:30 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/20 20:52:34 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_var_print_chr_left(int c, int *sol, t_options *flags)
{
	int	j;

	if (flags->point == 0)
		*sol = *sol + ft_printf_write_char(c, 1);
	j = 1;
	while (j < flags->width)
	{
		if (flags->zero == 0)
			while (j++ < flags->width)
				*sol = *sol + ft_printf_write_char(' ', 1);
		if (flags->zero == 1)
			while (j++ < flags->width)
				*sol = *sol + ft_printf_write_char('0', 1);
		j++;
	}
}

void	ft_var_print_chr_right(int c, int *sol, t_options *flags)
{
	int	j;
	
	j = 1;
	while (j < flags->width)
	{
		if (flags->zero == 0)
			while (j++ < flags->width)
				*sol = *sol + ft_printf_write_char(' ', 1);
		if (flags->zero == 1)
			while (j++ < flags->width)
				*sol = *sol + ft_printf_write_char('0', 1);
		j++;
	}
	if (flags->point == 0)
		*sol = *sol + ft_printf_write_char(c, 1);
}
