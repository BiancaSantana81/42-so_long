/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:58:21 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/28 14:56:15 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char		*dest;
	size_t		i;

	i = 0;
	dest = ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	if (dest == NULL)
	{
		return (NULL);
	}
	while (i <= (ft_strlen(s)))
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
