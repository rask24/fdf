/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:43:54 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/24 02:53:30 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_INTERNAL_H
# define EVENT_INTERNAL_H

# include "ctx.h"

int	handle_keydown(int keycode, t_ctx *ctx);
int	handle_mousedown(int button, int x, int y, t_ctx *ctx);
int	handle_mousemove(int x, int y, t_ctx *ctx);
int	handle_mouseup(int button, int x, int y, t_ctx *ctx);
int	exit_window(t_ctx *ctx);

#endif
