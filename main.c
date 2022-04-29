/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:39:25 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/29 21:49:25 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int	main(void)
{
	int				i;
	char			c = 'A';
	char			*string = "En un lugar de La Mancha...";
	void			*puntero = &c;
	int				entero = -10;
	int			intero = 10;
	float			numero = 3.141592;
	int			octal = 012345;
	unsigned int	sin_signo = 12345;
	int			hexadecimal = 0xabc23;
	int			HEXADECIMAL = 0XABC23;

	i = ft_printf("\e[39m%%d escribe un número decimal: %d\n", entero);
	printf("sol ft_printf = %d\n", i);
	i = printf("\e[32m%%d escribe un número decimal: %d\n", entero);
	printf("sol printf = %d\n", i);
	i = ft_printf("\e[39m%%c escribe un caracter: %c\n", c);
	printf("sol ft_printf = %d\n", i);
	i = printf("\e[32m%%c escribe un caracter: %c\n", c);
	printf("sol printf = %d\n", i);
	i = ft_printf("\e[39m%%s escribe un string: %s\n", string);
	printf("sol ft_printf = %d\n", i);
	i = printf("\e[32m%%s escribe un string: %s\n", string);
	printf("sol printf = %d\n", i);
	i = ft_printf("\e[39m%%p escribe un puntero: %p\n", puntero);
	printf("sol ft_printf = %d\n", i);
	i = printf("\e[32m%%p escribe un puntero: %p\n", puntero);
	printf("sol printf = %d\n", i);
	i = ft_printf("\e[39m%%i escribe numeros enteros: %i\n", intero);
	printf("sol ft_printf = %d\n", i);
	i = printf("\e[32m%%i escribe numeros enteros: %i\n", intero);
	printf("sol printf = %d\n", i);
	i = ft_printf("\e[39m%%o escribe numeros octales: %o\n", octal);
	printf("sol ft_printf = %d\n", i);
	i = printf("\e[32m%%o escribe numeros octales: %o\n", octal);
	printf("sol printf = %d\n", i);
	i = ft_printf("\e[39m%%u escribe un número sin signo: %u\n", sin_signo);
	printf("sol ft_printf = %d\n", i);
	i = printf("\e[32m%%u escribe un número sin signo: %u\n", sin_signo);
	printf("sol printf = %d\n", i);
	i = ft_printf("\e[39m%%x escribe hexadecimales en minusculas: %x\n", hexadecimal);
	printf("sol ft_printf = %d\n", i);
	i = printf("\e[32m%%x escribe hexadecimales en minusculas: %x\n", hexadecimal);
	printf("sol printf = %d\n", i);
	i = ft_printf("\e[39m%%X escribe hexadecimales en mayusculas: %X\n", HEXADECIMAL);
	printf("sol ft_printf = %d\n", i);
	i = printf("\e[32m%%X escribe hexadecimales en mayusculas: %X\n", HEXADECIMAL);
	printf("sol printf = %d\n", i);
	i = ft_printf("\e[39m%%f escribe un float: %f\n", numero);
	printf("sol ft_printf = %d\n", i);
	i = printf("\e[32m%%f escribe un float: %f\n", numero);
	printf("sol printf = %d\n", i);
	return (0);
}
