/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:21:47 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/23 17:16:44 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int			ft_printf_write(char c, int fd)
{
	write(fd, c, 1);
	return (1);
}

t_options	ft_printf_flags_init(t_options flags)
{                       
	flags->minus = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->pad = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision = 0;
	return (tab);
}

