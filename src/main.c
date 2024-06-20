/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:01:51 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/21 02:00:41 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	main(int argc, char **argv)
{
	validate_arguments(argc, argv);
	validate_map(argv[1]);
	return (0);
}
