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
	
	i = ft_printf("%%x %%x -> %x %x\n", LONG_MAX, LONG_MIN);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%x %%x -> %lx %lx\n", ULONG_MAX, -ULONG_MAX);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%x -> %x\n", 9223372036854775807LL);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%x -> %llx\n", 9223372036854775807LL);
	printf("sol printf = %d\n", i);
	i = ft_printf("%012x -> %012x\n", LONG_MIN);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%012x -> %012lx\n", (unsigned long)LONG_MIN);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%-12x -> %-12x\n", LONG_MIN);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%-12x -> %-12x\n", LONG_MIN);
	printf("sol ft_printf = %d\n", i);
	i = ft_printf("%%.5x -> %.5x\n", 16);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%.5x -> %.5x\n", 16);
	printf("sol ft_printf = %d\n", i);
	return (0);
}
