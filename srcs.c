/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:47:20 by annstepa          #+#    #+#             */
/*   Updated: 2022/11/03 20:47:24 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_steps(t_fdf *data, float *x_step, float *y_step, float *max)
{
	*x_step = data->cord.x1 - data->cord.x;
	*y_step = data->cord.y1 - data->cord.y;
	*max = max_f(mod_f(*x_step), mod_f(*y_step));
	*x_step /= *max;
	*y_step /= *max;
}
