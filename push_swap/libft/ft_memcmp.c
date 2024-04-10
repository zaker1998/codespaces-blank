/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdussali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:19:55 by mdussali          #+#    #+#             */
/*   Updated: 2023/09/12 18:01:19 by mdussali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*helps1;
	unsigned char	*helps2;

	i = 0;
	helps1 = (unsigned char *) s1;
	helps2 = (unsigned char *) s2;
	while (i < n)
	{
		if (helps1[i] != helps2[i])
		{
			return ((unsigned char) helps1[i] - (unsigned char) helps2[i]);
		}
		i++;
	}
	return (0);
}
