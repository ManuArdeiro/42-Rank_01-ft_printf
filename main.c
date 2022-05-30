/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:39:25 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/26 17:07:17 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int				i;
	
	i = ft_printf("%%x -> %x ", 0);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%x -> %x ", 0);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%-2p -> %-2p ", 1);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%-2p -> %-2d ", 1);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%-1X -> %-1X ", UINT_MAX);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%-1X -> %-1X ", UINT_MAX);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%-2p -> %-2p ", 15);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%-2p -> %-2p ", 1);
	printf("sol ft_printf = %d\n", i);
	return (0);
}
