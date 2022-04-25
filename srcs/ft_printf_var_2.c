/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:48:12 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/23 19:43:54 by jolopez-         ###   ########.fr       */
/*                                                                            */
	/* ************************************************************************** */


#include "libftprintf.h"

void	ft_var_print_nbr_left(int j, int *sol, t_options *flags)
{
	int		k;
	char	*str;

	k = 0;
	if (flags->plus == 1 && j > 0)
		*sol = *sol + ft_printf_write_char('+', 1);
	else if (flags->space == 1 && j > 0)
		*sol = *sol + ft_printf_write_char(' ', 1);
	else if (j < 0)
	{
		*sol = *sol + ft_printf_write_char('-', 1);
		j = j * -1;
	}
	while (j > 0)
	{
		//utilizar atoi?
		j = j / 10;
		k++;
	}
	
}

void	ft_var_print_nbr_right(int j, int *sol, t_options *flags)
{
}

void	ft_var_print_unsigned(unsigned int j, int *sol, t_options *flags)
{
}

void	ft_var_print_hex(char c, unsigned long int hex, int *sol, t_options *flags)
{
}
