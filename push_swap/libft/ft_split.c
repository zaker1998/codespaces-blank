/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdussali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:21:22 by mdussali          #+#    #+#             */
/*   Updated: 2023/09/14 13:02:31 by mdussali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	strcounter(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			count++;
		}
	}
	return (count);
}

static void	free_allocated_memory(char **arr, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	fillarr(char **arr, size_t len_arr, char const *s, char c)
{
	size_t	idx;
	size_t	len_word;

	idx = 0;
	while (idx < len_arr)
	{
		len_word = 0;
		while (*s == c && *s != 0)
			s++;
		while (s[len_word] != c && s[len_word] != '\0')
			len_word++;
		arr[idx] = ft_substr(s, 0, len_word);
		if (!arr[idx])
		{
			free_allocated_memory(arr, idx);
			return (0);
		}
		s += len_word;
		idx++;
	}
	arr[idx] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	len_arr;
	char	**arr;

	if (!s)
		return (0);
	len_arr = strcounter(s, c);
	arr = malloc(sizeof(char *) * (len_arr + 1));
	if (!arr)
		return (NULL);
	if (!fillarr(arr, len_arr, s, c))
	{
		return (NULL);
	}
	return (arr);
}
/* 
#include <stdio.h>
int main(void)
{
	char **result;
	char str[] = "This is a sample string to split on spaces.";
	char delimiter = ' ';
	int i = 0;

	result = ft_split(str, delimiter);
	if (!result)
	{
		printf("Error in memory allocation\n");
		return (1);
	}

	while (result[i] != NULL)
	{
		printf("Token %d: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);

	return (0);
} */
