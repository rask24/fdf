/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:31:03 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/21 19:37:03 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "utils.h"

void	error_exit(char *msg)
{
	ft_dprintf(STDERR_FILENO, "%s: %s\n", EXE_NAME, msg);
	exit(EXIT_FAILURE);
}
