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
	
	i = ft_printf("%%-2x -> %-2x ", -1);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%-2x -> %-2x ", -1);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%-13x -> %-13x ", UINT_MAX);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%-13x -> %-13x ", UINT_MAX);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%7s -> %%7s ", 0);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%7s -> %%7s ", 0);
	printf("sol printf = %d\n", i);
	return (0);
}
