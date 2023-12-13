/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:59:35 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/13 14:35:12 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

size_t	ft_printf_uint(char const format, va_list ap)
{
	size_t			len;
	unsigned int	u;
	char			*to_write;

	len = 0;
	u = va_arg(ap, unsigned int);
	to_write = ft_utoa_base(u, ft_baselen(format));
	len += ft_printf_putnbr(format, to_write);
	return (len);
}
