/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:21 by reasuke           #+#    #+#             */
/*   Updated: 2023/10/17 15:42:54 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fpf_parse_flags(t_format_spec *fs, t_format_result *fr)
{
	char		*ptr;
	ptrdiff_t	index;

	while (true)
	{
		ptr = ft_strchr(FLAGS, *fr->format);
		if (!ptr)
			break ;
		index = ptr - FLAGS;
		fs->flags |= 1 << index;
		fr->format++;
	}
}

static void	fpf_parse_width(t_format_spec *fs, t_format_result *fr, va_list *ap)
{
	if (*fr->format == '*')
	{
		fs->width = va_arg(*ap, int);
		if (fs->width < 0)
		{
			fs->width = -fs->width;
			fs->flags |= FLAG_MINUS;
		}
		fr->format++;
	}
	else
	{
		fs->width = ft_atoi(fr->format);
		while (ft_isdigit(*fr->format))
			fr->format++;
	}
}

static void	fpf_parse_precision(
				t_format_spec *fs, t_format_result *fr, va_list *ap)
{
	if (*fr->format == '.')
	{
		fr->format++;
		if (*fr->format == '*')
		{
			fs->precision = va_arg(*ap, int);
			fr->format++;
		}
		else
		{
			fs->precision = ft_atoi(fr->format);
			while (ft_isdigit(*fr->format))
				fr->format++;
		}
		if (fs->precision < 0)
			fs->precision = PREC_NONE;
	}
}

static void	fpf_parse_conversion(t_format_spec *fs, t_format_result *fr)
{
	if (!ft_strncmp(fr->format, "ll", 2))
		fs->length = LENGTH_LL;
	else if (!ft_strncmp(fr->format, "l", 1))
		fs->length = LENGTH_L;
	else if (!ft_strncmp(fr->format, "hh", 2))
		fs->length = LENGTH_HH;
	else if (!ft_strncmp(fr->format, "h", 1))
		fs->length = LENGTH_H;
	else if (!ft_strncmp(fr->format, "j", 1))
		fs->length = LENGTH_J;
	else if (!ft_strncmp(fr->format, "t", 1))
		fs->length = LENGTH_T;
	else if (!ft_strncmp(fr->format, "z", 1))
		fs->length = LENGTH_Z;
	while (ft_strchr("lhjtz", *fr->format))
		fr->format++;
	fs->conversion = *fr->format;
}

void	fpf_parse_spec(t_format_spec *fs, t_format_result *fr, va_list *ap)
{
	fr->format++;
	fpf_parse_flags(fs, fr);
	fpf_parse_width(fs, fr, ap);
	if (fs->flags & FLAG_MINUS && fs->flags & FLAG_ZERO)
		fs->flags &= ~FLAG_ZERO;
	fpf_parse_precision(fs, fr, ap);
	fpf_parse_conversion(fs, fr);
	fr->format++;
}
