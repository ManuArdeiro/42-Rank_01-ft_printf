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
	
	i = ft_printf("%%p %%p -> %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%p %%p -> %p %p ", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%-2p -> %-2p ", 1);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%-2p -> %-2p ", (void *)1);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%-2p -> %-2p ", 12);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%-2p -> %-2p ", (void *)12);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%.2x -> %.2x ", 1);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%.2x -> %.2x ", 1);
	printf("sol ft_printf = %d\n", i);
	i = ft_printf("%%.5x -> %.5x ", 16);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%.5x -> %.5x ", 16);
	printf("sol ft_printf = %d\n", i);
	return (0);
}
