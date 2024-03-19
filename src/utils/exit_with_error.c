/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:17:45 by reasuke           #+#    #+#             */
/*   Updated: 2023/11/28 22:05:50 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_with_error(char *message)
{
	ft_putstr_fd("fdf: ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	exit(1);
}
