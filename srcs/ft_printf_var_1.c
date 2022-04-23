/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:47:44 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/23 17:17:53 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_var_print_main(char c, va_list args, int *sol)
{
	if (c == 'c')
	{
		ft_printf_write(1, va_args(args, char), 1);
		*sol = *sol + 1;
	}
	if (c == 's')
		ft_var_print_str(va_args(args, char *), sol);
	if (c == 'p')
		ft_var_print_pointer(va_args(args, void *), sol);
	if (c == 'd' || c == 'i')
		ft_var_print_nbr(va_args(args, int), sol);
	if (c == 'u')
		ft_var_print_unsigned(va_args(args, unsigned int), sol);
	if (c == 'x' || c == 'X')
		ft_var_print_hex(c, va_args(args, unsigned long int), sol);
}

void	ft_var_print_str(char *str, int *sol)
{
}

void	ft_var_print_pointer(void *ptr, int *sol)
{
}

void	ft_var_print_nbr(int i, int *j)
{
}
