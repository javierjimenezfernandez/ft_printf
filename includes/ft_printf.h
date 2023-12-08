/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:55:32 by javjimen          #+#    #+#             */
/*   Updated: 2023/12/08 01:51:11 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./../libft/libft.h"

typedef struct s_format
{
	char				c;
	char				*s;
	unsigned long long	p;
	int					d;
	int					i;
	unsigned int		u;
	unsigned int		x;
}				t_format;

/* ft_printf */
size_t			ft_select_format(char const format, va_list ap, size_t len);
int				ft_printf(char const *format, ...);

/* ft_printf_utils.c */
void			ft_str_toupper(char *str);
int				is_negative(long long n);
int				ft_isnumeric(char format);
unsigned int	ft_baselen(char format);

/* ft_printf_num.c */
size_t			ft_numlen_base(long long n, unsigned int base_len);
char			*ft_ntoa_base(long long n, unsigned int base_len);
size_t			ft_numlen_ubase(unsigned long long n, unsigned int base_len);
char			*ft_utoa_base(unsigned long long n, unsigned int base_len);
size_t			ft_printf_putnbr(char format, char *to_write);

#endif
