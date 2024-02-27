/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:36:26 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/24 15:25:58 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
#include "libft.h"

# define DECIMAL_BASE "0123456789"
# define HEXA_UPPER_BASE "0123456789ABCDEF"
# define HEXA_LOWER_BASE "0123456789abcdef"

int		ft_printf(const char *type_format, ...);
int		ft_flags(char flag, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbase(long long n, char *base);
int		ft_pointer(unsigned long long n, char *base);

#endif
