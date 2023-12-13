/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:58:51 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/13 19:43:40 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int	ft_printf_int(char const format, va_list ap, int *len)
{
	int		i;
	char	*to_write;

	i = va_arg(ap, int);
	to_write = ft_itoa(i);
	if (!to_write)
	{
		*len = -1;
		return (*len);
	}
	(*len) += ft_printf_putnbr(format, to_write);
	free(to_write);
	return (*len);
}
