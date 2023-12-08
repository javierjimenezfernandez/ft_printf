/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:39:04 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/08 01:46:13 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

size_t	ft_numlen_base(long long n, unsigned int base_len)
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

char	*ft_ntoa_base(long long n, unsigned int base_len)
{
	char	*num;
	char	*base;
	size_t	num_len;
	int		neg_flag;

	base = "0123456789abcdefghijklmnopqrstuvwxyz";
	neg_flag = is_negative(n);
	num_len = ft_numlen_base(n, base_len);
	num = (char *)ft_calloc((num_len + 1), sizeof (char));
	if (!num)
		return (NULL);
	while (num_len--)
	{
		if (neg_flag)
		{
			if (num_len == 0)
				num[num_len] = '-';
			else
				num[num_len] = base[-n % base_len];
		}
		else
			num[num_len] = base[n % base_len];
		n /= base_len;
	}
	return (num);
}

size_t	ft_numlen_ubase(unsigned long long n, unsigned int base_len)
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
	num_len = ft_numlen_ubase(n, base_len);
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
