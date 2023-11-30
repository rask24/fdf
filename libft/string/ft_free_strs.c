/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:06:58 by reasuke           #+#    #+#             */
/*   Updated: 2023/11/03 15:10:30 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_strs(char **strs)
{
	char	**tmp;

	tmp = strs;
	while (*tmp)
		free(*tmp++);
	free(strs);
	return (NULL);
}
