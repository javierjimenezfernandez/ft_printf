/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_tester.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:32:36 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/22 15:33:45 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

	len1 = ft_printf("Aquí va una \"a\": %c\n", 'a');
	len2 = printf("Aquí va una \"a\": %c\n", 'a');
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	len1 = ft_printf("Cadena s = \"%s\"\n", s);
	len2 = printf("Cadena s = \"%s\"\n", s);
	ft_printf("return ft_printf = %i\n", len1);
	ft_printf("return    printf = %i\n", len2);

	p = s;
	len1 = ft_printf("Dirección de memoria p = \"%p\"\n", p);
	len2 = printf("Dirección de memoria p = \"%p\"\n", p);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	i1 = -8436576;
	len1 = ft_printf("Número decimal = \"%d\"\n", i1);
	len2 = printf("Número decimal = \"%d\"\n", i1);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	i1 = -5464;
	len1 = ft_printf("Número entero = \"%i\"\n", i1);
	len2 = printf("Número entero = \"%i\"\n", i1);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	u1 = 3147483647;
	len1 = ft_printf("Número decimal sin signo = \"%u\"\n", u1);
	len2 = printf("Número decimal sin signo = \"%u\"\n", u1);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	hexa = -437353553;
	len1 = ft_printf("Número hexadecimal = \"%x\"\n", hexa);
	len2 = printf("Número hexadecimal = \"%x\"\n", hexa);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	len1 = ft_printf("Número hexadecimal = \"%X\"\n", hexa);
	len2 = printf("Número hexadecimal = \"%X\"\n", hexa);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	len1 = ft_printf("Escribe un porcentaje = \"%%\"\n");
	len2 = printf("Escribe un porcentaje = \"%%\"\n");
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	return (0);
}
