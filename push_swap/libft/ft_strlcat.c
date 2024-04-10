/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdussali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:20:46 by mdussali          #+#    #+#             */
/*   Updated: 2023/09/12 17:52:11 by mdussali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size <= len_dest)
		return (size + len_src);
	i = 0;
	while (src[i] != '\0' && (len_dest + i + 1 < size))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
/*
#include <stdio.h>
int	main(void)
{
	char *src = {"End"};
	//char dest[7] = {"Start"};
	char dest[20] = {"Start"};
	
	unsigned int size = 20;
	
	unsigned int result = ft_strlcat(dest, src, size);
	
	if (result >= size)
	{
	printf("%s", "Truncation Happend!\n");
	}
	else
	{
	printf("%s", "Cancatentaion Success!\n");
	printf("%u\n", result);
    }
}
*/
