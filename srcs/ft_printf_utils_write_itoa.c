/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_write_itoa.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:21:47 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/10 20:23:55 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_write_itoa(int j, int *sol, t_options *flags)
{
	int		len;
	char	*str;

	if (j == 0)
		*sol = *sol + ft_printf_write_char('0', 1);
	if (j < 0)
		j = ft_sign_change(j, sol);
	len = ft_printf_itoa_len(j);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
	{
		free (str);
		*sol = -1;
		return ;
	}
	str[len] = '\0';
	while (j > 0)
	{
		str[--len] = '0' + j % 10;
		j = (j / 10);
	}
	while (str[len] && len <= flags->precision)
		*sol = *sol + ft_printf_write_char(str[len++], 1);
	free(str);
}

void	ft_printf_write_itoa_no_sign(unsigned int j, int *sol, t_options *flags)
{
	int		len;
	char	*str;

	if (j == 0)
		*sol = *sol + ft_printf_write_char('0', 1);
	len = ft_printf_itoa_unsigned_len(j);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
	{
		free (str);
		*sol = -1;
		return ;
	}
	str[len] = '\0';
	while (j > 0)
	{
		str[--len] = '0' + j % 10;
		j = (j / 10);
	}
	while (str[len] && len <= flags->precision)
		*sol = *sol + ft_printf_write_char(str[len++], 1);
	free(str);
}
