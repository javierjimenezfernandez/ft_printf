/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:55:15 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/13 14:45:41 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

size_t	ft_select_format(char const format, va_list ap, size_t len)
{
	if (format == 'c')
		len += ft_printf_char(ap);
	else if (format == 's')
		len += ft_printf_string(ap);
	else if (format == 'p')
		len += ft_printf_pointer(format, ap);
	else if (format == 'd' || format == 'i')
		len += ft_printf_int(format, ap);
	else if (format == 'u')
		len += ft_printf_uint(format, ap);
	else if (format == 'x' || format == 'X')
		len += ft_printf_hexa(format, ap);
	else if (format == '%')
		len += ft_printf_percent(format);
	return (len);
}

int	ft_printf(char const *format, ...)
{
	size_t	len;
	va_list	ap;

	if (!format)
		return (0);
	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len = ft_select_format(*format, ap, len);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}
