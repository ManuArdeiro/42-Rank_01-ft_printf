/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:54:00 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/08 14:24:48 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_var_print(char const *text, va_list args, int *i, int *sol)
{
	t_options	*flags;

	if (text[*i] == '%')
	{
		ft_printf_write_char(text[*i], 1);
		*i = *i + 1;
		*sol = *sol + 1;
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
