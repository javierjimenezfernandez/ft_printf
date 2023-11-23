/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:55:32 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/22 16:49:47 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_format
{
	char			c;
	char			*s;
	void			*p;
	int				d;
	int				i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;
}				t_format;

int		ft_printf(char const *format, ...);
void	ft_str_toupper(char *str);
size_t	ft_numlen_base(long n, unsigned int base_len);
char	*ft_ntoa_base(long n, unsigned int base_len);

#endif
