/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_manage_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:14:00 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/08 18:37:05 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_var_set_length(int length, char c, int *i)
{	
	length = (length * 10) + (c - '0');
	*i = *i + 1;
	return (length);
}

static void	ft_var_set_flags(t_options *flags, char c, int *i)
{
	if (c == '-')
		flags->minus = 1;
	if (c == '+')
		flags->plus = 1;
	if (c == ' ')
		flags->space = 1;
	if (c == '0')
		flags->zero = 1;
	if (c == '#')
		flags->pad = 1;
	*i = *i +1;
}

static void	ft_var_read_flags(char const *text, int *i, t_options *flags)
{
	while (text[*i] == '-' || text[*i] == '0' || text[*i] == '#'
		|| text[*i] == ' ' || text[*i] == '+')
		ft_var_set_flags(flags, text[*i], i);
	while ((text[*i] >= '0' && text[*i] <= '9'))
		flags->width = ft_var_set_length(flags->width, text[*i], i);
	if (text[*i] == '.')
	{
		*i = *i + 1;
		while (text[*i] >= '0' && text[*i] <= '9')
			flags->precision = ft_var_set_length(flags->precision, text[*i], i);
	}
}
