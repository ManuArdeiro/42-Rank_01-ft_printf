/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:21:47 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/01 18:26:45 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_itoa_len_hex(unsigned long int hex)
{
	int     len;

	len = 0;
	while (hex > 0)
	{
		hex = hex / 16;
		len++;
	}
	return (len);
}

void	ft_printf_write_itoa_hex(char c, unsigned long int hex, int *sol)
{
	char	*hex_digits;
	char	*HEX_digits;

	hex_digits = "0123456789abcdef";
	HEX_digits = "0123456789ABCDEF";
	if (c == 'x')
	{
		*sol = *sol + ft_printf_write_char('0', 1);
		*sol = *sol + ft_printf_write_char('x', 1);
		ft_printf_write_hex(hex, sol, hex_digits);
	}
	if (c == 'X')
	{
		*sol = *sol + ft_printf_write_char('0', 1);
		*sol = *sol + ft_printf_write_char('X', 1);
		ft_printf_write_HEX(hex, sol, HEX_digits);
	}
}

void	ft_printf_write_hex(unsigned long int hex, int *sol, char *digits)

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
	str[len] = '\0';
	len--;
	while (hex != 0)
	{
		str[len] = digits[hex % 16];
		hex = (hex / 16);
		len--;
	}
	len = 0;
	while (str[len])
		*sol = *sol + ft_printf_write_char(str[len++], 1);
}

void ft_printf_write_HEX(unsigned long int HEX, int *sol, char *digits)

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
	str[len] = '\0';
	len--;
	while (HEX != 0)
	{
		str[len] = digits[HEX % 16];
		HEX = (HEX / 16);
		len--;
	}
	len = 0;
	while (str[len])
		*sol = *sol + ft_printf_write_char(str[len++], 1);
}
