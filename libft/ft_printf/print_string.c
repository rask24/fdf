/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:02:59 by reasuke           #+#    #+#             */
/*   Updated: 2023/10/17 15:43:52 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fpf_print_padding(char c, int len)
{
	while (len-- > 0)
		ft_putchar_fd(c, STDOUT_FILENO);
}

void	fpf_print_char(char c, t_format_spec *fs, t_format_result *fr)
{
	if (fs->width && !(fs->flags & FLAG_MINUS) && !(fs->flags & FLAG_ZERO))
		fpf_print_padding(' ', fs->width - 1);
	else if (fs->width && !(fs->flags & FLAG_MINUS) && fs->flags & FLAG_ZERO)
		fpf_print_padding('0', fs->width - 1);
	ft_putchar_fd(c, STDOUT_FILENO);
	if (fs->width && fs->flags & FLAG_MINUS)
		fpf_print_padding(' ', fs->width - 1);
	if (fs->width)
		fr->cnt += fs->width;
	else
		fr->cnt++;
}

void	fpf_print_str(char *str, t_format_spec *fs, t_format_result *fr)
{
	int	str_len;

	if (!str)
		str = STR_NULL;
	str_len = ft_strlen(str);
	if (fs->precision != PREC_NONE && fs->precision < str_len)
		str_len = fs->precision;
	if (fs->width && !(fs->flags & FLAG_MINUS) && !(fs->flags & FLAG_ZERO))
		fpf_print_padding(' ', fs->width - str_len);
	else if (fs->width && !(fs->flags & FLAG_MINUS) && fs->flags & FLAG_ZERO)
		fpf_print_padding('0', fs->width - str_len);
	write(STDOUT_FILENO, str, str_len);
	if (fs->width && fs->flags & FLAG_MINUS)
		fpf_print_padding(' ', fs->width - str_len);
	fr->cnt += fpf_max(fs->width, str_len);
}
