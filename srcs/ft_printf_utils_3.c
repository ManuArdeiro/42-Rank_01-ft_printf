/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:52:53 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/04 21:07:42 by jolopez-         ###   ########.fr       */
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
