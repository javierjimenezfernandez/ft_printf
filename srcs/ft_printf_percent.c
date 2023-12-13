/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:00:36 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/13 14:43:52 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

size_t	ft_printf_percent(char const format)
{
	size_t	len;

	len = 0;
	ft_putchar_fd(format, 1);
	len++;
	return (len);
}
