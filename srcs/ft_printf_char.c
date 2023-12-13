/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:55:37 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/13 14:28:55 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

size_t	ft_printf_char(va_list ap)
{
	size_t	len;
	char	c;

	len = 0;
	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	len++;
	return (len);
}
