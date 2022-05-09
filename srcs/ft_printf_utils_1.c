/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:21:47 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/08 16:24:59 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_write_char(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

t_options	*ft_printf_flags_init(t_options *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->pad = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision = -1;
	return (flags);
}

void	ft_printf_write_itoa(int j, int *sol)
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
	while (str[len])
		*sol = *sol + ft_printf_write_char(str[len++], 1);
	free(str);
}
