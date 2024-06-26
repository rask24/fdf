/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:09:35 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/24 23:09:49 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <stdbool.h>

# include "ctx.h"

void	render(t_ctx *ctx);
void	prep_render(t_ctx *ctx, bool is_clean);

#endif
