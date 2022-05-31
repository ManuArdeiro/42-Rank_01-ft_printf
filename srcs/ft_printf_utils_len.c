/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:21:47 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/08 16:24:59 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_strlen(char *str)
{
	int	k;

	k = 0;
	while (str[k])
		k++;
	return (k);
}

int	ft_printf_itoa_len(int j)
{
	int	len;

	if (j == 0)
		return (1);
	if (j == -2147483648)
		return (10);
	else if (j < 0)
		j = j * -1;
	len = 0;
	while (j > 0)
	{
		j = j / 10;
		len++;
	}
	return (len);
}

int	ft_printf_itoa_len_hex(unsigned long int hex)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (hex != 0)
	{
		hex = hex / 16;
		len++;
	}
	return (len);
}

int	ft_printf_itoa_unsigned_len(unsigned int j)
{
	int	len;

	len = 0;
	if (j == 0)
		return (1);
	while (j > 0)
	{
		j = j / 10;
		len++;
	}
	return (len);
}
