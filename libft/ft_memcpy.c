/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:52:56 by bsantana          #+#    #+#             */
/*   Updated: 2023/11/08 10:59:45 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src || n == 0)
	{
		return (dest);
	}
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
	}
	return (dest);
}
