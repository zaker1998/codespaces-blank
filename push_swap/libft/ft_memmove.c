/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdussali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:20:42 by mdussali          #+#    #+#             */
/*   Updated: 2023/09/12 17:33:56 by mdussali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == src || n == 0)
	{
		return (dest);
	}
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (s < d)
	{
		s += n;
		d += n;
		while (n--)
			*(--d) = *(--s);
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
/* #include <stdio.h>
#include <string.h>

int main() {
    // 1. Basic Test
    char src1[] = "Hello, World!";
    char dest1[50] = {};
    ft_memmove(dest1, src1, strlen(src1) + 1);
    printf("Basic Test: %s\n", dest1);

    // 2. Null `src` 
    //char *src2 = NULL;
    //char dest2[50] = {};
    //ft_memmove(dest2, src2, 5);

    // 3. Null `dest` 
    //char src3[] = "Test";
    //char *dest3 = NULL;
    //ft_memmove(dest3, src3, strlen(src3) + 1);

    // 4. Overlapping Test towards beginning
    char buffer1[50] = "OverlapTest";
    ft_memmove(buffer1, buffer1 + 2, 10);
    printf("Overlapping Test towards beginning: %s\n", buffer1);

    // 5. Overlapping Test towards end
    char buffer2[50] = "OverlapTest";
    ft_memmove(buffer2 + 2, buffer2, 10);
    printf("Overlapping Test towards end: %s\n", buffer2);

    // 6. Zero Size Test
    char src6[] = "DoNotMove";
    char dest6[50] = "InitialString";
    ft_memmove(dest6, src6, 0);
    printf("Zero Size Test: %s\n", dest6);

    return 0;
} */