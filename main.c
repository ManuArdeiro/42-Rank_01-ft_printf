/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:39:25 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/21 19:56:45 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int				i;
//	char			c = 'A';
//	char			*string = "En un lugar de La Mancha...";
//	void			*puntero = &c;
//	int				entero = -2147483648;
//	int				intero = -2147483648;
//	unsigned int	sin_signo = -125;
//	int				hexadecimal = 0;
//	int				HEXADECIMAL = 0;
	i = ft_printf("%%-3d -> %-3d ", 1);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%-3d -> %-3d ", 1);
	printf("sol printf = %d\n", i);
//	i = ft_printf(" %d \n", -42);
//	printf("sol ft_printf = %d\n", i);
//	i = printf(" %d \n", -42);
//	printf("sol printf = %d\n", i);
//	i = ft_printf("%%s escribe una cadena: %s\n", string);
//	printf("sol ft_printf = %d\n", i);
//	i = printf("%%s escribe una cadena: %s\n", string);
//	printf("sol printf = %d\n", i);
//	i = printf("printf: NULL %s NULL \n", NULL);
//	printf("sol printf = %d\n", i);
//	i = ft_printf("ft_printf: NULL %s NULL \n", NULL);
//	printf("sol ft_printf = %d\n", i);
//	i = printf("printf: %s\n", string);
//	printf("sol printf = %d\n", i);
//	i = ft_printf("ft_printf: %s \n", string);
//	printf("sol ft_printf = %d\n", i);
//	i = printf("printf: NULL  %10.3s NULL \n", NULL);
//	printf("sol printf = %d\n", i);
//	i = ft_printf(" NULL  %10.3s NULL \n", NULL);
//	printf("sol ft_printf = %d\n", i);
//	i = printf(" NULL  %50.3s NULL \n", string);
//	printf("sol printf = %d\n", i);
//	i = ft_printf(" NULL  %50.3s NULL \n", string);
//	printf("sol ft_printf = %d\n", i);
//	i = ft_printf("%%p escribe un puntero: %p\n", puntero);
//	printf("sol ft_printf = %d\n", i);
//	i = printf("%%p escribe un puntero: %p\n", puntero);
//	printf("sol printf = %d\n", i);
//	i = ft_printf("%%i escribe numeros enteros: %i\n", 12345);
//	printf("sol ft_printf = %d\n", i);
//	i = printf("%%i escribe numeros enteros: %i\n", 12345);
//	printf("sol printf = %d\n", i);
//	i = ft_printf("%%i escribe numeros enteros: %10.3i\n", 12345);
//	printf("sol ft_printf = %d\n", i);
//	i = printf("%%i escribe numeros enteros: %10.3i\n", 12345);
//	printf("sol printf = %d\n", i);
//	i = ft_printf("%%i escribe numeros enteros: %10.3i\n", -12345);
//	printf("sol ft_printf = %d\n", i);
//	i = printf("%%i escribe numeros enteros: %10.3i\n", -12345);
//	printf("sol printf = %d\n", i);
//	i = ft_printf("%%u escribe un número sin signo: %u\n", sin_signo);
//	i = ft_printf("%%u escribe un número sin signo: %u\n", sin_signo);
//	i = ft_printf("%%u escribe un número sin signo: %u\n", sin_signo);
//	printf("sol ft_printf = %d\n", i);
//	i = printf("%%u escribe un número sin signo: %u\n", sin_signo);
//	printf("sol printf = %d\n", i);
//	i = ft_printf("%%x escribe hexadecimales en minusculas: %x\n", LONG_MAX);
//	printf("sol ft_printf = %x\n", i);
//	i = printf("%%x escribe hexadecimales en minusculas: %x\n", (unsigned int)LONG_MAX);
//	printf("sol printf = %x\n", i);
//	i = ft_printf("%%X escribe hexadecimales en mayusculas: %X\n", LONG_MIN);
//	printf("sol ft_printf = %d\n", i);
//	i = printf("%%X escribe hexadecimales en mayusculas: %X\n", (unsigned int)LONG_MIN);
//	printf("sol printf = %d\n", i);
	return (0);
}
