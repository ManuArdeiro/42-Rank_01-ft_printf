/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:21:47 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/28 19:54:35 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_itoa_len_hex(unsigned long int hex)
{
	int     len;

	len = 0;
	while (hex > 0)
	{
		hex = hex / 10;
		len++;
	}
	return (len);
}

void	ft_printf_write_itoa_hex(char c, int hex, int *sol)
{
	char	*hex_digits;
	char	*HEX_digits;

	hex_digits = "0123456789abcdef";
	HEX_digits = "0123456789ABCDEF";
	if (c == 'x')
		ft_printf_write_hex(hex, sol, hex_digits);
	if (c == 'X')
		ft_printf_write_HEX(hex, sol, HEX_digits);
}

void	ft_printf_write_hex(int hex, int *sol, char *digits)

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
		str[len] = digits[hex % 16];
		hex = (hex / 16);
		len--;
	}
	while (str[len++])
		*sol = *sol + ft_printf_write_char(str[len], 1);
}

void ft_printf_write_HEX(int HEX, int *sol, char *digits)

{
	int		len;
	char	*str;

	len = ft_printf_itoa_len_hex(HEX);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
	{
		free (str);
		*sol = -1;
		return ;
	}
	str[len + 1] = '\0';
	while (HEX != 0)
	{
		str[len] = digits[HEX % 16];
		HEX = (HEX / 16);
		len--;
	}
	while (str[len++])
		*sol = *sol + ft_printf_write_char(str[len], 1);
}
