/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:15:55 by reasuke           #+#    #+#             */
/*   Updated: 2023/11/30 19:30:03 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <malloc/malloc.h>

long	ft_strtol(const char *str, char **endptr, int base);

void	put_void_colon(void *ptr)
{
	printf(":::%s:::\n", ptr);
}

void	del(void *ptr)
{
	if (malloc_size(ptr))
		free(ptr);
}

void	*double_str(void *ptr)
{
	char	*ret;
	char	*tmp;

	tmp = ptr;
	ret = ft_strjoin(ptr, ptr);
	del(ptr);
	if (!ret)
		return (NULL);
	return (ret);
}

int	main(void)
{
	char	**line_array;

	line_array = file_to_line_array("sample.txt");
	while (*line_array)
		printf("%s\n", *line_array++);
}
