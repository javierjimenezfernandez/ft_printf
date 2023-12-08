/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:55:15 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/08 01:49:59 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

size_t	ft_select_format(char const format, va_list ap, size_t len)
{
	t_format	data_type;
	char		*to_write;

	if (format == 'c')
	{
		data_type.c = va_arg(ap, int);
		ft_putchar_fd(data_type.c, 1);
		len++;
	}
	else if (format == 's')
	{
		data_type.s = va_arg(ap, char *);
		if (data_type.s)
		{
			ft_putstr_fd(data_type.s, 1);
			len += ft_strlen(data_type.s);
		}
		else
		{
			ft_putstr_fd("(null)", 1);
			len += ft_strlen("(null)");
		}
	}
	else if (ft_isnumeric(format))
	{
		if (format == 'p')
		{
			data_type.p = va_arg(ap, unsigned long long);
			if (data_type.p)
			{
				to_write = ft_utoa_base(data_type.p, ft_baselen(format));
				len += ft_printf_putnbr(format, to_write);
			}
			else
			{
				ft_putstr_fd("(nil)", 1);
				len += ft_strlen("(nil)");
			}
		}
		else if (format == 'd' || format == 'i')
		{
			data_type.d = va_arg(ap, int);
			to_write = ft_ntoa_base(data_type.d, ft_baselen(format));
			len += ft_printf_putnbr(format, to_write);
		}
		else if (format == 'u')
		{
			data_type.u = va_arg(ap, unsigned int);
			to_write = ft_utoa_base(data_type.u, ft_baselen(format));
			len += ft_printf_putnbr(format, to_write);
		}
		else if (format == 'x')
		{
			data_type.x = va_arg(ap, unsigned int);
			to_write = ft_utoa_base(data_type.x, ft_baselen(format));
			len += ft_printf_putnbr(format, to_write);
		}
		else if (format == 'X')
		{
			data_type.x = va_arg(ap, unsigned int);
			to_write = ft_utoa_base(data_type.x, ft_baselen(format));
			len += ft_printf_putnbr(format, to_write);
		}
	}
	else if (format == '%')
	{
		ft_putchar_fd(format, 1);
		len++;
	}
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
			format++;
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
