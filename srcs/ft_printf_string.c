/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:56:58 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/13 19:53:33 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int	ft_printf_string(va_list ap, int *len)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s)
	{
		while (*s)
		{
			if (write(1, s, 1) == -1)
			{
				(*len) = -1;
				return (-1);
			}
			else
				(*len)++;
			s++;
		}
	}
	else
	{
		if (write(1, "(null)", 6) == -1)
		{
			(*len) = -1;
			return (-1);
		}
		else
			(*len) += 6;
	}
	return (*len);
}
