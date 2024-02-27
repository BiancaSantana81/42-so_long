/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:26:54 by bsantana          #+#    #+#             */
/*   Updated: 2023/11/08 11:35:52 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		*t;

	t = malloc(nmemb * size);
	if (t == NULL)
	{
		return (t);
	}
	ft_bzero(t, nmemb * size);
	return (t);
}
