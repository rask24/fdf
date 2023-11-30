/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_router.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:13:31 by reasuke           #+#    #+#             */
/*   Updated: 2023/10/17 15:42:54 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fpf_signed_integer_router(
				t_format_spec *fs, t_format_result *fr, va_list *ap)
{
	if (fs->length == LENGTH_NONE)
		fpf_print_integer(va_arg(*ap, int), fs, fr);
	else if (fs->length == LENGTH_L)
		fpf_print_integer(va_arg(*ap, long), fs, fr);
	else if (fs->length == LENGTH_LL)
		fpf_print_integer(va_arg(*ap, long long), fs, fr);
	else if (fs->length == LENGTH_H)
		fpf_print_integer((short)va_arg(*ap, int), fs, fr);
	else if (fs->length == LENGTH_HH)
		fpf_print_integer((signed char)va_arg(*ap, int), fs, fr);
	else if (fs->length == LENGTH_J)
		fpf_print_integer(va_arg(*ap, intmax_t), fs, fr);
	else if (fs->length == LENGTH_T)
		fpf_print_integer(va_arg(*ap, ptrdiff_t), fs, fr);
	else if (fs->length == LENGTH_Z)
		fpf_print_integer(va_arg(*ap, ssize_t), fs, fr);
}

static void	fpf_unsigned_integer_router(
				t_format_spec *fs, t_format_result *fr, va_list *ap)
{
	if (fs->length == LENGTH_NONE)
		fpf_print_integer(va_arg(*ap, unsigned int), fs, fr);
	else if (fs->length == LENGTH_L)
		fpf_print_integer(va_arg(*ap, unsigned long), fs, fr);
	else if (fs->length == LENGTH_LL)
		fpf_print_integer(va_arg(*ap, unsigned long long), fs, fr);
	else if (fs->length == LENGTH_H)
		fpf_print_integer((unsigned short)va_arg(*ap, int), fs, fr);
	else if (fs->length == LENGTH_HH)
		fpf_print_integer((unsigned char)va_arg(*ap, int), fs, fr);
	else if (fs->length == LENGTH_J)
		fpf_print_integer(va_arg(*ap, uintmax_t), fs, fr);
	else if (fs->length == LENGTH_T)
		fpf_print_integer(va_arg(*ap, ptrdiff_t), fs, fr);
	else if (fs->length == LENGTH_Z)
		fpf_print_integer(va_arg(*ap, size_t), fs, fr);
}

static void	fpf_n_router(
				t_format_spec *fs, t_format_result *fr, va_list *ap)
{
	if (fs->length == LENGTH_NONE)
		*va_arg(*ap, int *) = fr->cnt;
	else if (fs->length == LENGTH_L)
		*va_arg(*ap, long *) = fr->cnt;
	else if (fs->length == LENGTH_LL)
		*va_arg(*ap, long long *) = fr->cnt;
	else if (fs->length == LENGTH_H)
		*va_arg(*ap, short *) = fr->cnt;
	else if (fs->length == LENGTH_HH)
		*va_arg(*ap, signed char *) = fr->cnt;
	else if (fs->length == LENGTH_J)
		*va_arg(*ap, intmax_t *) = fr->cnt;
	else if (fs->length == LENGTH_T)
		*va_arg(*ap, ptrdiff_t *) = fr->cnt;
	else if (fs->length == LENGTH_Z)
		*va_arg(*ap, ssize_t *) = fr->cnt;
}

void	fpf_conversion_router(
			t_format_spec *fs, t_format_result *fr, va_list *ap)
{
	if (fs->conversion == '%')
		fpf_print_char('%', fs, fr);
	else if (fs->conversion == 'c')
		fpf_print_char(va_arg(*ap, int), fs, fr);
	else if (fs->conversion == 's')
		fpf_print_str(va_arg(*ap, char *), fs, fr);
	else if (fs->conversion == 'd' || fs->conversion == 'i')
		fpf_signed_integer_router(fs, fr, ap);
	else if (ft_strchr("uxXo", fs->conversion))
		fpf_unsigned_integer_router(fs, fr, ap);
	else if (fs->conversion == 'p')
		fpf_print_integer(va_arg(*ap, uintptr_t), fs, fr);
	else if (fs->conversion == 'n')
		fpf_n_router(fs, fr, ap);
}
