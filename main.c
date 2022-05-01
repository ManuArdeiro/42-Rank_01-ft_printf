/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:39:25 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/01 20:13:42 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int	main(void)
{
	int				i;
	char			c = 'A';
//	char			*string = "En un lugar de La Mancha...";
	void			*puntero = 0;
	int				entero = -10;
	int			intero = 10;
	int			octal = 012345;
	unsigned int	sin_signo = 12345;
	int			hexadecimal = 0xabc23;
	int			HEXADECIMAL = 0XABC23;

	i = ft_printf("%%d escribe un número decimal: %d\n", entero);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%d escribe un número decimal: %d\n", entero);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%c escribe un caracter: %c\n", c);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%c escribe un caracter: %c\n", c);
	printf("sol printf = %d\n", i);
	i = ft_printf(" NULL  %s NULL \n", NULL);
	printf("sol ft_printf = %d\n", i);
	i = printf(" NULL  %s NULL \n", NULL);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%p escribe un puntero: %p\n", puntero);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%p escribe un puntero: %p\n", puntero);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%i escribe numeros enteros: %i\n", intero);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%i escribe numeros enteros: %i\n", intero);
	printf("sol printf = %d\n", i);
	i = ft_printf("\e[39m%%o escribe numeros octales: %o\n", octal);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%o escribe numeros octales: %o\n", octal);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%u escribe un número sin signo: %u\n", sin_signo);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%u escribe un número sin signo: %u\n", sin_signo);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%x escribe hexadecimales en minusculas: %x\n", hexadecimal);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%x escribe hexadecimales en minusculas: %x\n", hexadecimal);
	printf("sol printf = %d\n", i);
	i = ft_printf("%%X escribe hexadecimales en mayusculas: %X\n", HEXADECIMAL);
	printf("sol ft_printf = %d\n", i);
	i = printf("%%X escribe hexadecimales en mayusculas: %X\n", HEXADECIMAL);
	printf("sol printf = %d\n", i);
	return (0);
}
