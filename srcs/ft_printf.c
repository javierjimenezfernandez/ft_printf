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

#include "./../includes/ft_printf.h"

size_t	ft_select_format(char const **format, va_list ap, size_t len)
{
	t_format	data_type;
	char		*to_write;

	if (**format == 'c')
	{
		data_type.c = va_arg(ap, int);
		ft_putchar_fd(data_type.c , 1);
		len++;
		(*format)++;
	}
	else if (**format == 's')
	{
		data_type.s = va_arg(ap, char *);
		ft_putstr_fd(data_type.s, 1);
		len += ft_strlen(data_type.s);
		(*format)++;
	}
	else if (**format == 'p')
	{
		data_type.p = va_arg(ap, void *);
		to_write = ft_ntoa_base((long)data_type.p, 16);
		write(1, "0x", 2);
		len += 2;
		ft_putstr_fd(to_write, 1);
		len += ft_strlen(to_write);
		free(to_write);
		(*format)++;
	}
	else if (**format == 'd' || **format == 'i')
	{
		data_type.d = va_arg(ap, int);
		to_write = ft_ntoa_base(data_type.d, 10);
		ft_putstr_fd(to_write, 1);
		len += ft_strlen(to_write);
		free(to_write);
		(*format)++;
	}
	else if (**format == 'u')
	{
		data_type.u = va_arg(ap, unsigned int);
		to_write = ft_ntoa_base(data_type.u, 10);
		ft_putstr_fd(to_write, 1);
		len += ft_strlen(to_write);
		free(to_write);
		(*format)++;
	}
	else if (**format == 'x')
	{
		data_type.x = va_arg(ap, unsigned int);
		to_write = ft_ntoa_base(data_type.x, 16);
		ft_putstr_fd(to_write, 1);
		len += ft_strlen(to_write);
		free(to_write);
		(*format)++;
	}
	else if (**format == 'X')
	{
		data_type.X = va_arg(ap, unsigned int);
		to_write = ft_ntoa_base(data_type.X, 16);
		ft_str_toupper(to_write);
		ft_putstr_fd(to_write, 1);
		len += ft_strlen(to_write);
		free(to_write);
		(*format)++;
	}
	else if (**format == '%')
	{
		ft_putchar_fd(**format , 1);
		len++;
		(*format)++;
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
			len = ft_select_format(&format, ap, len);
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
