/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:05:36 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/01 18:36:16 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_printf_itoa_len_octal(unsigned int octal)
{
	int     len;

	len = 0;
	while (octal > 0)
	{
		octal = octal / 8;
		len++;
	}
	return (len);
}

void    ft_printf_write_octal(unsigned int octal, int *sol)
{
	char    *octal_digits;
	char	*str;
	int		len;

	octal_digits = "01234567";
	*sol = *sol + ft_printf_write_char('0', 1);
	len = ft_printf_itoa_len_octal(octal);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
	{
		free (str);
		*sol = -1;
		return ;
	}
	str[len] = '\0';
	len--;
	while (octal != 0)
	{
		str[len] = octal_digits[octal % 8];
		octal = (octal / 8);
		len--;
	}
	len = 0;
	while (str[len])
		*sol = *sol + ft_printf_write_char(str[len++], 1);
}
