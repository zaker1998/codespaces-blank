/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdussali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:19:42 by mdussali          #+#    #+#             */
/*   Updated: 2023/09/12 17:30:47 by mdussali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*helps;
	unsigned char	helpc;
	size_t			i;

	helps = (unsigned char *) s;
	helpc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (helps[i] == helpc)
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}
