/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:55:15 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/22 16:49:04 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				to_write = ft_xtoa((ssize_t)data_type.p);
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
				to_write = ft_xtoa((ssize_t)data_type.x);
				write(1, to_write, ft_strlen(to_write));
				len += ft_strlen(to_write);
				free(to_write);
				format++;
			}
			else if (*format == 'X')
			{
				data_type.X = va_arg(ap, int);
				to_write = ft_Xtoa((ssize_t)data_type.X);
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
