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

#include "ft_printf.h"

char	*ft_xtoa(ssize_t n)
{
	char	*num;
	char	base[] = "0123456789abcdef";
	size_t	num_len;
	int		neg_flag;

	neg_flag = 0;
	num_len = ft_numlenx(n);
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
				num[num_len] = base[n % 16];
		}
		else
			num[num_len] = base[n % 16];
		n /= 16;
	}
	return (num);
}

char	*ft_Xtoa(ssize_t n)
{
	char	*num;
	char	base[] = "0123456789ABCDEF";
	size_t	num_len;
	int		neg_flag;

	neg_flag = 0;
	num_len = ft_numlenx(n);
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
				num[num_len] = base[n % 16];
		}
		else
			num[num_len] = base[n % 16];
		n /= 16;
	}
	return (num);
}

char	*ft_utoa(unsigned int n)
{
	char			*num;
	unsigned int	num_len;

	num_len = ft_numlend(n);
	num = (char *)ft_calloc((num_len + 1), sizeof (char));
	if (!num)
		return (NULL);
	while (num_len--)
	{
		num[num_len] = '0' + (n % 10);
		n /= 10;
	}
	return (num);
}

size_t	ft_numlend(ssize_t n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	ft_numlenx(ssize_t n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

size_t	ft_numlen_base(ssize_t n, size_t base_len)
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

char	*ft_ntoa_base(ssize_t n, size_t base_len)
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
