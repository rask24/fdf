/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:20:27 by reasuke           #+#    #+#             */
/*   Updated: 2023/11/10 22:27:55 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

# define OCT_BASE       "01234567"
# define DEC_BASE       "0123456789"
# define HEX_BASE_UPPER "0123456789ABCDEF"
# define HEX_BASE_LOEWR "0123456789abcdef"

# define FLAGS "-+ #0"

# define FLAG_NONE  0b00000
# define FLAG_MINUS 0b00001
# define FLAG_PLUS  0b00010
# define FLAG_SPACE 0b00100
# define FLAG_HASH  0b01000
# define FLAG_ZERO  0b10000

# define WIDTH_NONE 0

# define PREC_NONE -1

# define LENGTH_NONE 0
# define LENGTH_L    1
# define LENGTH_LL   2
# define LENGTH_H    3
# define LENGTH_HH   4
# define LENGTH_J    5
# define LENGTH_T    6
# define LENGTH_Z    7

# define STR_NULL "(null)"

# define OCT_PREFIX       "0"
# define HEX_PREFIX_LOWER "0x"
# define HEX_PREFIX_UPPER "0X"

typedef struct s_format_result
{
	const char	*format;
	int			cnt;
}	t_format_result;

typedef struct s_format_spec
{
	int		flags;
	int		width;
	int		precision;
	int		length;
	char	conversion;
}	t_format_spec;

typedef struct s_integer_info
{
	bool	is_signed;
	char	*base;
	char	*prefix;
	int		space_width;
	int		zero_width;
	int		prefix_width;
	int		digits;
}	t_integer_info;

int		ft_printf(const char *format, ...);

void	fpf_parse_spec(t_format_spec *fs, t_format_result *fr, va_list *ap);
void	fpf_conversion_router(
			t_format_spec *fs, t_format_result *fr, va_list *ap);
void	fpf_print_char(char c, t_format_spec *fs, t_format_result *fr);
void	fpf_print_str(char *str, t_format_spec *fs, t_format_result *fr);
void	fpf_print_padding(char c, int len);
void	fpf_print_integer(intmax_t nb, t_format_spec *fs, t_format_result *fr);
void	fpf_putnbr_base(intmax_t nb, const char *base, bool is_signed);
int		fpf_digits_base(intmax_t nb, size_t radix, bool is_signed);
int		fpf_max(int a, int b);

#endif
