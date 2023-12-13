/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_tester.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:32:36 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/08 01:55:38 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "./../includes/ft_printf.h"

int	main(void)
{
	int				len1;
	int				len2;
	int				i1;
	unsigned int	u1;
	int				hexa;
	char			s[] = "Hola";
	char			*p;

	printf("\nTEST 1\n");
	len1 = ft_printf("Caracter \'a\' ft_printf = %c\n", 'a');
	len2 = printf("Caracter \'a\'    printf = %c\n", 'a');
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	printf("\nTEST 2\n");
	len1 = ft_printf("Cadena s ft_printf = \"%s\"\n", s);
	len2 = printf("Cadena s    printf = \"%s\"\n", s);
	ft_printf("return ft_printf = %i\n", len1);
	ft_printf("return    printf = %i\n", len2);

	printf("\nTEST 3\n");
	len1 = ft_printf("Cadena NULL ft_printf = \"%s\"\n", (char *)NULL);
	//len2 = printf("Cadena NULL    printf = \"%s\"\n", (char *)NULL);
	ft_printf("return ft_printf = %i\n", len1);
	//ft_printf("return    printf = %i\n", len2);

	printf("\nTEST 4\n");
	p = s;
	len1 = ft_printf("Dirección de memoria p ft_printf = \"%p\"\n", p);
	len2 = printf("Dirección de memoria p    printf = \"%p\"\n", p);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	printf("\nTEST 5\n");
	len1 = ft_printf("Dirección de memoria 0 ft_printf = \"%p\"\n", (void *)0);
	len2 = printf("Dirección de memoria 0    printf = \"%p\"\n", (void *)0);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	printf("\nTEST 6\n");
	len1 = ft_printf("Dirección de memoria LONG_MIN ft_printf = \"%p\"\n", (void *)LONG_MIN);
	len2 = printf("Dirección de memoria LONG_MIN    printf = \"%p\"\n", (void *)LONG_MIN);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	printf("\nTEST 7\n");
	len1 = ft_printf("Dirección de memoria LONG_MAX ft_printf = \"%p\"\n", (void *)LONG_MAX);
	len2 = printf("Dirección de memoria LONG_MAX    printf = \"%p\"\n", (void *)LONG_MAX);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	printf("\nTEST 8\n");
	len1 = ft_printf("Dirección de memoria ULONG_MAX ft_printf = \"%p\"\n", (void *)ULONG_MAX);
	len2 = printf("Dirección de memoria ULONG_MAX    printf = \"%p\"\n", (void *)ULONG_MAX);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	printf("\nTEST 9\n");
	len1 = ft_printf("Dirección de memoria -ULONG_MAX ft_printf = \"%p\"\n", (void *)(-ULONG_MAX));
	len2 = printf("Dirección de memoria -ULONG_MAX    printf = \"%p\"\n", (void *)(-ULONG_MAX));
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	printf("\nTEST 10\n");
	i1 = -8436576;
	len1 = ft_printf("Número decimal ft_printf = \"%d\"\n", i1);
	len2 = printf("Número decimal    printf = \"%d\"\n", i1);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	printf("\nTEST 11\n");
	i1 = -5464;
	len1 = ft_printf("Número entero ft_printf = \"%i\"\n", i1);
	len2 = printf("Número entero    printf = \"%i\"\n", i1);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	printf("\nTEST 12\n");
	u1 = 3147483647;
	len1 = ft_printf("Número decimal sin signo ft_printf = \"%u\"\n", u1);
	len2 = printf("Número decimal sin signo    printf = \"%u\"\n", u1);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	printf("\nTEST 13\n");
	hexa = -437353553;
	len1 = ft_printf("Número hexadecimal ft_printf = \"%x\"\n", hexa);
	len2 = printf("Número hexadecimal    printf = \"%x\"\n", hexa);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	printf("\nTEST 14\n");
	len1 = ft_printf("Número hexadecimal en mayúsculas ft_printf = \"%X\"\n", hexa);
	len2 = printf("Número hexadecimal en mayúsculas    printf = \"%X\"\n", hexa);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	printf("\nTEST 15\n");
	len1 = ft_printf("Escribe un porcentaje ft_printf = \"%%\"\n");
	len2 = printf("Escribe un porcentaje    printf = \"%%\"\n");
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	return (0);
}
