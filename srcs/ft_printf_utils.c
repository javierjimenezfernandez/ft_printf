/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:30:03 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/24 18:41:21 by javjimen         ###   ########.fr       */
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

int	is_negative(long n)
{
	if (n < 0)
		return (1);
	else
		return (0);
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
