/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:55:32 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/24 18:56:16 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./../libft/libft.h"

typedef struct s_format
{
	char			c;
	char			*s;
	void			*p;
	int				d;
	int				i;
	unsigned int	u;
	unsigned int	x;
}				t_format;

/* ft_printf */
size_t	ft_select_format(char const format, va_list ap, size_t len);
int		ft_printf(char const *format, ...);

/* ft_printf_utils.c */
void	ft_str_toupper(char *str);
size_t	ft_numlen_base(long n, unsigned int base_len);
char	*ft_ntoa_base(long n, unsigned int base_len);

/* ft_printf_num.c */
int				ft_isnumeric(char format);
unsigned int	ft_baselen(char format);
size_t			ft_printf_putnbr(char format, char *to_write);

#endif
