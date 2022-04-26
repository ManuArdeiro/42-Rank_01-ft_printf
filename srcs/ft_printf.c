/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:54:00 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/23 20:55:53 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_var_set_length(int length, char c, int *i)
{	
	length = (length * 10) + (c - '0');
	*i = *i + 1;
	return (length);
}

static void	ft_var_set_flags(t_options *flags, char c, int *i)
{
	if (c == '-')
		flags->minus = 1;
	if (c == '+')
		flags->plus = 1;
	if (c == ' ')
		flags->space = 1;
	if (c == '0')
		flags->zero = 1;
	if (c == '#')
	{
		flags->pad = 1;
		if 
	*i = *i +1;
}

static void	ft_var_print(char const *text, va_list args, int *i, int *sol)
{
	t_options	*flags;

	flags = ft_printf_flags_init(flags);
	if (!flags)
	{:w

		*sol = -1;
	   	return ;
	}
	if (text[*i] == '%')
		ft_printf_write_char(text[*i], 1);
	while (text[*i] == '-' || text[*i] == '0' || text[*i] == '.' ||
			text[*i] == '#' || text[*i] == ' ' || text[*i] == '+')
		ft_var_set_flags(flags, text[*i], i);
	while ((text[*i] >= '0' && text[*i] <= '9'))
		flags->width = ft_var_set_length(flags->width, text[*i], i);
	if (text[*i] == '.')
	{
		*i = *i + 1;
		while (text[*i] >= '0' && text[*i] <= '9')
			flags->precision = ft_var_set_length(flags->precision, text[*i], i);
	}
	ft_var_print_main(text[*i], args, sol, flags);
	*i = *i + 1;
	return ;
}

int			ft_printf(char const *text, ...)
{
	int		*i;
	int		*sol;
	va_list	args;

	i = 0;
	sol = 0;
	va_start(args, text);
	while (text[*i])
	{
		if (text[*i] == '%')
		{
			*i = *i + 1;
			ft_var_print(text, args, i, sol);
			if (*sol = -1)
				return (-1);
		}
		if (text[*i])
		{
			*sol = *sol + ft_printf_write_char(text[*i], 1);
			*i = *i + 1;
		}
	}
	va_end(args);
	return (*sol);
}

/*int			main(void)
{
	char			c = 'A';
	char			*string = "En un lugar de La Mancha...";
	void			*puntero = &c;
	int				entero = -10;
	int				intero = 10;
	float			numero = 3.141592;
	int				octal = 012345;
	unsigned int	sin_signo = 12345;
	int 			hexadecimal = 0xabc23;
	int				HEXADECIMAL = 0XABC23;
		
	ft_printf("%%d escribre un número decimal: %d\n", entero);
	ft_printf("%%c escribe un caracter: %c\n", c);
	ft_printf("%%s escribe un string: %s\n", string);
	ft_printf("%%p escribe un puntero: %p\n", puntero);
	ft_printf("%%i escribe numeros enteros: %i\n", intero);
	ft_printf("%%o escribe numeros octales: %o\n", octal);
	ft_printf("%%u escribe un número sin signo: %u\n", sin_signo);
	ft_printf("%%x escribe hexadecimales en minusculas: %x\n", hexadecimal);
	ft_printf("%%X escribe hexadecimales en mayusculas: %X\n", HEXADECIMAL);
	ft_printf("%%f escribe un float: %f\n", numero);
	return (0);
}*/
