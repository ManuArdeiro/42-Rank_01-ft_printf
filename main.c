#include "libftprintf.h"

int			main(void)
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
  printf("%%d escribre un número decimal: %d\n", entero);
	ft_printf("%%c escribe un caracter: %c\n", c);
  printf("%%c escribe un caracter: %c\n", c);
	ft_printf("%%s escribe un string: %s\n", string);
  printf("%%s escribe un string: %s\n", string);
	ft_printf("%%p escribe un puntero: %p\n", puntero);
  printf("%%p escribe un puntero: %p\n", puntero);
	ft_printf("%%i escribe numeros enteros: %i\n", intero);
  printf("%%i escribe numeros enteros: %i\n", intero);
	ft_printf("%%o escribe numeros octales: %o\n", octal);
  printf("%%o escribe numeros octales: %o\n", octal);
	ft_printf("%%u escribe un número sin signo: %u\n", sin_signo);
  printf("%%u escribe un número sin signo: %u\n", sin_signo);
	ft_printf("%%x escribe hexadecimales en minusculas: %x\n", hexadecimal);
  printf("%%x escribe hexadecimales en minusculas: %x\n", hexadecimal);
	ft_printf("%%X escribe hexadecimales en mayusculas: %X\n", HEXADECIMAL);
  printf("%%X escribe hexadecimales en mayusculas: %X\n", HEXADECIMAL);
	ft_printf("%%f escribe un float: %f\n", numero);
  printf("%%f escribe un float: %f\n", numero);
	return (0);
}
