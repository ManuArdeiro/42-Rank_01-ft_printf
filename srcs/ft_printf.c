/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:54:00 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/23 17:16:14 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int	ft_var_set_length(char c, int *i)
{
	length = (lenght * 10) + (c - '0');
	*i = *i + 1;
	return (length);
}

static void	ft_var_set_flags(char c, int *i)
{
	if (c == "-")
		flags->minus = 1;
	if (c == "+")
		flags->plus = 1;
	if (c == " ")
		flags->space = 1;
	if (c == "0")
		flags->zero = 1;
	if (c == "#")
		flags->pad = 1;
	*i = *i +1;
}

static void	ft_var_print(char const *text, va_list args, int *i, int *sol)
{
	t_options	flags;
	int			length;

	ft_flags_init(flags);
	length = 0;
	if (text[*i] == '%')
		ft_%_print_%(void);
	while (text[*i] == "-" || text[*i] == "0" || text[*i] == "." ||
			text[*i] == "#" || text[*i] == " " || text[*i] == "+")
		ft_%_set_flags(text[*i], i);
	while ((text[*i] >= '0' && text[*i] <=9))
		flags->width = ft_%_set_length(text[*i], i);
	if (text[*i] == '.')
	{
		*i = *i + 1;
		length = 0;
		while (text[*i] >= '0' && text[*i] <= '9')
			flags->precision = ft_%_set_length(text[*i], i);
	}
	ft_%_print_var(text[*i], args, sol);
	*i = *i + 1;
	return ;
}

int		ft_printf(char const *text, ...)
{
	int		*i;
	int		*sol;
	va_list	args;

	*i = 0;
	*sol = 0;
	va_start(args, text);
	while (text[i])
	{
		if (text[*i] == '%')
		{
			*i = *i + 1;
			ft_%_print(text, args, i, sol);
		}
		else
			*sol = *sol + ft_write(text[*i], 1);
		*i = *i + 1;
	}
	va_end(args);
	return (sol);
}

int	main(void)
{
	char			c = 'A';
	char			*string = "En un lugar de La Mancha...";
	void			*puntero;
	int				entero = -10;
	int				intero = 10;
	float			numero = 3.141592;
	int				octal = 012345;
	unsigned int	sin_signo = 12345;
	int 			hexadecimal = 0xabc23;
	int				HEXADECIMAL = 0XABC23;
		
	ft_printf("%%d escribre un número decimal: %d\n
			%%c escribe un caracter: %c\n
			%%s escribe un string: %s\n
			%%p escribe un puntero: %p\n
			%%i escribe numeros enteros: %i\n
			%%o escribe numeros octales: %o\n
			%%u escribe un número sin signo: %u\n
			%%x escribe hexadecimales en minusculas: %x\n
			%%X escribe hexadecimales en mayusculas: %X\n,
			%%f escribe un float",
			entero, c, string, puntero, intero, octal, sin_signo,
			hexadecimal, HEXADECIMAL, numero);
	return (0);
}
