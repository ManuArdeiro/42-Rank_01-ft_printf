/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:21:47 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/26 19:04:48 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_write_char(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

t_options	*ft_printf_flags_init(t_options *flags)
{
	flags = malloc(sizeof(t_options) * 1);
	if (!flags)
	{
		free(flags);
		return (NULL);
	}
	flags->minus = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->pad = 0;
	flags->space = 0;
	flags->width = -1;
	flags->precision = -1;
	return (flags);
}

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

	while (j > 9)
	{
		j = j / 10;
		len++;
	}
	return (len);
}

void	ft_printf_write_itoa(int j, int *sol, t_options *flags)
{
	int		len;
	char	*str;

	if (j < 0)
		j = j * -1;
	len = ft_printf_itoa_len (j);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len + 1] = '\0';
	if (!str)
	{
		free (str);
		*sol = -1;
		return ;
	}
	while (j != 0)
	{
		str[len] = '0' + n % 10;
		n = (n / 10);
		len--;
	}
	while (str[len++])
		*sol = *sol + ft_printf_write_char(str[len], 1);
}
