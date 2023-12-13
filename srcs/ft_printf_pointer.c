/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:57:50 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/13 17:38:22 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

size_t	ft_printf_pointer(char const format, va_list ap)
{
	size_t				len;
	unsigned long long	p;
	char				*to_write;

	len = 0;
	p = va_arg(ap, unsigned long long);
	to_write = ft_utoa_base(p, ft_baselen(format));
	len += ft_printf_putnbr(format, to_write);
	return (len);
}
