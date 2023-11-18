/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:55:15 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/18 23:48:59 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	int			len;
	char		*to_write;
	t_format	data_type;
	va_list		ap;

	// 1st check if the format string is correct
	// Then read the format string and find the % identifiers
	// When done initialize the va_start and copy it so you don't modify the 
	// original (?)
	len = 0;
	va_start(ap, format);
	// After that, use the va_arg macro to search for the types
	// found inside the string
	// TIP: man va_start
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				data_type.c = va_arg(ap, int);
				write(1, &data_type.c, 1);
				len++;
				format++;
			}
			else if (*format == 's')
			{
				data_type.s = va_arg(ap, char *);
				write(1, data_type.s, ft_strlen(data_type.s));
				len += ft_strlen(data_type.s);
				format++;
			}
			else if (*format == 'p')
			{
				data_type.p = va_arg(ap, void *);
				to_write = ft_xtoa((size_t)data_type.p);
				write(1, "0x", 2);
				len += 2;
				write(1, to_write, ft_strlen(to_write));
				len += ft_strlen(to_write);
				free(to_write);
				format++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				data_type.d = va_arg(ap, int);
				to_write = ft_itoa(data_type.d);
				write(1, to_write, ft_strlen(to_write));
				len += ft_strlen(to_write);
				free(to_write);
				format++;
			}
			else if (*format == 'u')
			{
				data_type.d = va_arg(ap, unsigned int);
				to_write = ft_utoa(data_type.d);
				write(1, to_write, ft_strlen(to_write));
				len += ft_strlen(to_write);
				free(to_write);
				format++;
			}

			else if (*format == 'x')
			{
				data_type.x = va_arg(ap, int);
				to_write = ft_xtoa((size_t)data_type.x);
				write(1, to_write, ft_strlen(to_write));
				len += ft_strlen(to_write);
				free(to_write);
				format++;
			}
			else if (*format == 'X')
			{
				data_type.X = va_arg(ap, int);
				to_write = ft_Xtoa((size_t)data_type.X);
				write(1, to_write, ft_strlen(to_write));
				len += ft_strlen(to_write);
				free(to_write);
				format++;
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				len++;
				format++;
			}
			else // What to do?
				return (0);
		}
		else
		{
			write(1, format, 1);	
			len++;
			format++;
		}
	}
	va_end(ap);
	return (len);
}

char	*ft_xtoa(size_t n)
{
	char	*num;
	char	base[] = "0123456789abcdef";
	size_t	num_len;
	int		neg_flag;

	neg_flag = 0;
	num_len = ft_numlenx(n);
	num = (char *)ft_calloc((num_len + 1), sizeof (char));
	if (!num)
		return (NULL);
	if (n < 0)
		neg_flag = 1;
	while (num_len--)
	{
		if (neg_flag)
		{
			if (num_len == 0)
				num[num_len] = '-';
			else
				num[num_len] = base[n % 16];
		}
		else
			num[num_len] = base[n % 16];
		n /= 16;
	}
	return (num);
}

char	*ft_Xtoa(size_t n)
{
	char	*num;
	char	base[] = "0123456789ABCDEF";
	size_t	num_len;
	int		neg_flag;

	neg_flag = 0;
	num_len = ft_numlenx(n);
	num = (char *)ft_calloc((num_len + 1), sizeof (char));
	if (!num)
		return (NULL);
	if (n < 0)
		neg_flag = 1;
	while (num_len--)
	{
		if (neg_flag)
		{
			if (num_len == 0)
				num[num_len] = '-';
			else
				num[num_len] = base[n % 16];
		}
		else
			num[num_len] = base[n % 16];
		n /= 16;
	}
	return (num);
}

char	*ft_utoa(unsigned int n)
{
	char			*num;
	unsigned int	num_len;

	num_len = ft_numlend(n);
	num = (char *)ft_calloc((num_len + 1), sizeof (char));
	if (!num)
		return (NULL);
	while (num_len--)
	{
		num[num_len] = '0' + (n % 10);
		n /= 10;
	}
	return (num);
}

size_t	ft_numlend(ssize_t n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	ft_numlenx(ssize_t n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	main(void)
{
	int				len1;
	int				len2;
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

	u1 = 3147483647;
	len1 = ft_printf("Número unsigned int = \"%u\"\n", u1);
	len2 = printf("Número unsigned int = \"%u\"\n", u1);
	ft_printf("return ft_printf = %d\n", len1);
	ft_printf("return    printf = %d\n", len2);

	hexa = 215437953;
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
