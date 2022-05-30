/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_write_hex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:21:47 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/06 19:24:06 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void	ft_printf_write_itoa_hex(char c, unsigned long int hex, int *sol)
{
	char	*hex_digits_l;
	char	*hex_digits_u;

	hex_digits_l = "0123456789abcdef";
	hex_digits_u = "0123456789ABCDEF";
	if (c == 'x')
		ft_printf_write_hex_l(hex, sol, hex_digits_l);
	if (c == 'X')
		ft_printf_write_hex_u(hex, sol, hex_digits_u);
}

void	ft_printf_write_hex_l(unsigned long int hex_l, int *sol, char *digits)

{
	int		len;
	char	*str;

	len = ft_printf_itoa_len_hex(hex_l);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
	{
		free (str);
		*sol = -1;
		return ;
	}
	str[len] = '\0';
	len--;
	if (hex_l == 0)
		*sol = *sol + ft_printf_write_char('0', 1);
	while (hex_l != 0)
	{
		str[len] = digits[hex_l % 16];
		hex_l = (hex_l / 16);
		len--;
	}
	len = 0;
	while (str[len])
		*sol = *sol + ft_printf_write_char(str[len++], 1);
	free(str);
}

void	ft_printf_write_hex_u(unsigned long int hex_u, int *sol, char *digits)

{
	int		len;
	char	*str;

	len = ft_printf_itoa_len_hex(hex_u);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
	{
		free (str);
		*sol = -1;
		return ;
	}
	str[len] = '\0';
	len--;
	if (hex_u == 0)
		*sol = *sol + ft_printf_write_char('0', 1);
	while (hex_u != 0)
	{
		str[len] = digits[hex_u % 16];
		hex_u = (hex_u / 16);
		len--;
	}
	len = 0;
	while (str[len])
		*sol = *sol + ft_printf_write_char(str[len++], 1);
	free(str);
}
