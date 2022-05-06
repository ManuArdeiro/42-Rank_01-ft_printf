/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:52:53 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/06 18:02:56 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sign_change(int j, int *sol)
{
	if (j == -2147483648)
	{
		*sol = *sol + ft_printf_write_char('2', 1);
		return (147483648);
	}
	else if (j < 0)
		j = j * -1;
	return (j);
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

void	ft_printf_write_itoa_unsigned(unsigned int j, int *sol)
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
	while (str[len])
		*sol = *sol + ft_printf_write_char(str[len++], 1);
	free(str);
}
