/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:39:04 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/24 18:51:33 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int	ft_isnumeric(char format)
{
	if (format == 'p' || format == 'd' || format == 'i' || \
		format == 'u' || format == 'x' || format == 'X')
		return (1);
	else
		return (0);
}

unsigned int	ft_baselen(char format)
{
	unsigned int	base_len;

	base_len = 10;
	if (format == 'p' || format == 'x' || format == 'X')
		base_len = 16;
	return (base_len);
}

size_t	ft_printf_putnbr(char format, char *to_write)
{
	size_t			len;

	len = 0;
	if (format == 'p')
	{
		ft_putstr_fd("0x", 1);
		len += 2;
	}
	if (format == 'X')
	{
		ft_str_toupper(to_write);
	}
	ft_putstr_fd(to_write, 1);
	len += ft_strlen(to_write);
	free(to_write);
	return (len);
}
