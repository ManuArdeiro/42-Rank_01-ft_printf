/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_flags_init.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:21:47 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/10 20:09:54 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_options	*ft_printf_flags_init(t_options *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->pad = 0;
	flags->space = 0;
	flags->width = 0;
	flags->point = 0;
	flags->precision = 0;
	return (flags);
}
