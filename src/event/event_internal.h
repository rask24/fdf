/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:43:54 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/25 19:58:56 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_INTERNAL_H
# define EVENT_INTERNAL_H

# include "ctx.h"

# define TRANSLATION_STEP		10
# define ROTATION_STEP_KEY		0.1
# define ROTATION_STEP_MOUSE	0.002
# define SCALE_STEP				0.1

int	handle_keydown(int keycode, t_ctx *ctx);
int	handle_mousedown(int button, int x, int y, t_ctx *ctx);
int	handle_mousemove(int x, int y, t_ctx *ctx);
int	handle_mouseup(int button, int x, int y, t_ctx *ctx);
int	exit_window(t_ctx *ctx);

#endif
