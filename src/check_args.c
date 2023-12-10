/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:58:46 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/10 14:35:00 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	_check_arg_num(int argc)
{
	if (argc != 2)
		exit_with_error("number of arguments is invalid");
}

static char	*_extract_filename(char *path)
{
	char	*file_name;

	file_name = ft_strrchr(path, '/');
	if (file_name)
		return (file_name + 1);
	return (path);
}

static void	_check_filename(char *path)
{
	char	*file_name;
	char	*extension;

	file_name = _extract_filename(path);
	extension = ft_strrchr(file_name, '.');
	if (!ft_strcmp(file_name, ".fdf"))
		exit_with_error("wrong filename(.fdf)");
	if (!extension)
		exit_with_error("wrong filename");
	if (ft_strcmp(extension, ".fdf"))
		exit_with_error("wrong file extension");
}

void	check_args(int argc, char **argv)
{
	_check_arg_num(argc);
	_check_filename(argv[1]);
}
