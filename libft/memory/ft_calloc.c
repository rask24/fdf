/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:17:23 by reasuke           #+#    #+#             */
/*   Updated: 2023/10/12 19:06:41 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (count && SIZE_MAX / count < size)
		return (NULL);
	ret = malloc(count * size);
	if (!ret)
		return (NULL);
	return (ft_memset(ret, 0, count * size));
}
