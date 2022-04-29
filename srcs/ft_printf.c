/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:54:00 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/28 21:25:43 by jolopez-         ###   ########.fr       */
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

static void	ft_var_print(char const *text, va_list args, int *i, int *sol)
{
	t_options	*flags;

	if (text[*i] == '%')
	{
		ft_printf_write_char(text[*i], 1);
		*i = *i + 1;
		return ;
	}
	flags = malloc(sizeof(t_options) * 1);
	if (!flags)
	{
		*sol = -1;
		free(flags);
		return ;
	}
	flags = ft_printf_flags_init(flags);
	ft_var_read_flags(text, i, flags);
	ft_var_print_main(text[*i], args, sol, flags);
	free(flags);
	*i = *i + 1;
	return ;
}

int	ft_printf(char const *text, ...)
{
	int		i;
	int		sol;
	va_list	args;

	i = 0;
	sol = 0;
	va_start(args, text);
	while (text[i])
	{
		if (text[i] == '%')
		{
			i = i + 1;
			ft_var_print(text, args, &i, &sol);
			if (sol == -1)
				return (-1);
		}
		else if (text[i])
		{
			sol = sol + ft_printf_write_char(text[i], 1);
			i = i + 1;
		}
	}
	va_end(args);
	return (sol);
}
