/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:56:58 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/13 14:28:46 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

size_t	ft_printf_string(va_list ap)
{
	size_t	len;
	char	*s;

	len = 0;
	s = va_arg(ap, char *);
	if (s)
	{
		ft_putstr_fd(s, 1);
		len += ft_strlen(s);
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		len += ft_strlen("(null)");
	}
	return (len);
}
