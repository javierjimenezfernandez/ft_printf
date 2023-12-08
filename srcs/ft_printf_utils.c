/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:30:03 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/08 01:45:52 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

void	ft_str_toupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

int	is_negative(long long n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

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
