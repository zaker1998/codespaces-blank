#include "libft.h"
#include <stdio.h>

int main()
{
    //Test ft_isalpha.c
    printf("%d : ft_isalpha.c" , ft_isalpha('a'));
    printf("%d : ft_isalpha.c" , ft_isalpha('!'));
    printf("%d : ft_isalpha.c" , ft_isalpha(61));
    return(0);
}