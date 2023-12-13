/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:30:03 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/13 14:04:39 by javjimen         ###   ########.fr       */
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

unsigned int	ft_baselen(char format)
{
	unsigned int	base_len;

	base_len = 10;
	if (format == 'p' || format == 'x' || format == 'X')
		base_len = 16;
	return (base_len);
}

size_t	ft_ulen_base(unsigned long long n, unsigned int base_len)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_utoa_base(unsigned long long n, unsigned int base_len)
{
	char	*num;
	char	*base;
	size_t	num_len;

	base = "0123456789abcdefghijklmnopqrstuvwxyz";
	num_len = ft_ulen_base(n, base_len);
	num = (char *)ft_calloc((num_len + 1), sizeof (char));
	if (!num)
		return (NULL);
	while (num_len--)
	{
		num[num_len] = base[n % base_len];
		n /= base_len;
	}
	return (num);
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
