/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:57:50 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/13 19:43:56 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int	ft_printf_pointer(char const format, va_list ap, int *len)
{
	unsigned long long	p;
	char				*to_write;

	p = va_arg(ap, unsigned long long);
	to_write = ft_utoa_base(p, ft_baselen(format));
	if (!to_write)
	{
		*len = -1;
		return (*len);
	}
	(*len) += ft_printf_putnbr(format, to_write);
	free(to_write);
	return (*len);
}
