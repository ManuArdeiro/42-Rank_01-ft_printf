/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:21:47 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/27 12:24:48 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_itoa_len_hex(unsigned long int hex)
{
	int     len;

	while (hex > 0)
	{
		hex = hex / 10;
		len++;
	}
	return (len);
}

int	ft_printf_write_itoa_hex(char c, int hex, int *sol, t_options *flags)
{
	int		len;
	char	*str;

	len = ft_printf_itoa_len_hex(hex);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
	{
		free (str);
		*sol = -1;
		return ;
	}
	str[len + 1] = '\0';
	while (hex != 0)
	{
		if (c == 'x')
			str[len] = hex_digits[hex % 16];
		if (c == 'X')
			str[len] = HEX_DIGITS[hex % 16];
		hex = (hex / 16);
		len--;
	}
	while (str[len++])
		*sol = *sol + ft_printf_write_char(str[len], 1);
}
