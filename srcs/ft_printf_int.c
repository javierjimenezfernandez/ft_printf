/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:58:51 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/13 14:33:14 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

size_t	ft_printf_int(char const format, va_list ap)
{
	size_t	len;
	int		i;
	char	*to_write;

	len = 0;
	i = va_arg(ap, int);
	to_write = ft_itoa(i);
	len += ft_printf_putnbr(format, to_write);
	return (len);
}
