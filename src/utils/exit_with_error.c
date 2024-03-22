/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:17:45 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/22 14:40:02 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	exit_with_error(char *message)
{
	ft_putstr_fd("fdf: ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	exit(1);
}
