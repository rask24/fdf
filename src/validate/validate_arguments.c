/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:19:46 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/21 19:38:17 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

#include "validate_internal.h"

static void	_validate_number_of_arguments(int argc)
{
	if (argc == 2)
		return ;
	error_exit(INV_ARGS_ERR_MSG);
}

static void	_validate_file_format(char *file_path)
{
	char	*ext;

	ext = ft_strrchr(file_path, '.');
	if (ext && ext != file_path && ft_strcmp(ext, ".fdf") == 0)
		return ;
	error_exit(INV_FILE_FORMAT_ERR_MSG);
}

void	validate_arguments(int argc, char **argv)
{
	_validate_number_of_arguments(argc);
	_validate_file_format(argv[1]);
}
