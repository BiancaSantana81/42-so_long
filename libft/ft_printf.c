/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:05:13 by bsantana          #+#    #+#             */
/*   Updated: 2023/12/13 14:53:39 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *type_format, ...)
{
	va_list	args;
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (!type_format)
		return (-1);
	va_start(args, type_format);
	while (type_format[i])
	{
		if (type_format[i] == '%' && type_format[i + 1] != '\0')
			result += ft_flags(type_format[++i], args);
		else
			result += ft_putchar(type_format[i]);
		i++;
	}
	va_end(args);
	return (result);
}
