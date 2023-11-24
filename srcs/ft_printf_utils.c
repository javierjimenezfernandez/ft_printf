/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:30:03 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/22 16:50:03 by javjimen         ###   ########.fr       */
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

size_t	ft_numlen_base(long n, unsigned int base_len)
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

char	*ft_ntoa_base(long n, unsigned int base_len)
{
	char	*num;
	char	*base;
	size_t	num_len;
	int		neg_flag;

	base = "0123456789abcdefghijklmnopqrstuvwxyz";
	neg_flag = 0;
	num_len = ft_numlen_base(n, base_len);
	num = (char *)ft_calloc((num_len + 1), sizeof (char));
	if (!num)
		return (NULL);
	if (n < 0)
		neg_flag = 1;
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

size_t	ft_putnbr_base(long n, unsigned int base_len, char const **format, t_format data_type, unsigned int base_len)
{
	size_t			len;
	char			*to_write;

	len = 0;
	to_write = ft_ntoa_base((long)data_type.p, base_len);
	if (**format == 'p')
	{
		write(1, "0x", 2);
		len += 2;
	}
	ft_putstr_fd(to_write, 1);
	len += ft_strlen(to_write);
	free(to_write);
	(*format)++;
	return (len);
}
