/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdussali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:20:04 by mdussali          #+#    #+#             */
/*   Updated: 2023/09/14 14:28:44 by mdussali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
	{
		return (NULL);
	}
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}
/* #include <stdio.h>
#include <string.h>

int main() {
    char src1[] = "Hello, World!";
    char dest1[50];
    ft_memcpy(dest1, src1, strlen(src1) + 1);
    printf("Basic Test: %s\n", dest1);

	char buffer[50] = "OverlapTest";
    ft_memcpy(buffer + 2, buffer, 10);
    printf("Overlapping Test: %s\n", buffer);

    char src5[] = "DoNotCopy";
    char dest5[50] = "InitialString";
    ft_memcpy(dest5, src5, 0);
    printf("Zero Size Test: %s\n", dest5);
    // 2. Null `src`

    char *src2 = NULL;
    char dest2[50];
    ft_memcpy(dest2, src2, 5);  

    // Null `dest`
    char src3[] = "Test";
    char *dest3 = NULL;
    ft_memcpy(dest3, src3, strlen(src3) + 1); 

    return (0);
} */
