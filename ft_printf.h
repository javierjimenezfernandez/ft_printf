/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:55:32 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/18 23:46:06 by javjimen         ###   ########.fr       */
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
	int				x;
	int				X;
}				t_format;

int		ft_printf(char const *format, ...);
char	*ft_xtoa(size_t n);
char	*ft_Xtoa(size_t n);
char	*ft_utoa(unsigned int n);
size_t	ft_numlenx(ssize_t n);
size_t	ft_numlend(ssize_t n);

#endif
