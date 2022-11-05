/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:45:33 by annstepa          #+#    #+#             */
/*   Updated: 2022/11/03 20:45:36 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	max_f(float x, float y)
{
	if (x < y)
		return (y);
	return (x);
}

float	mod_f(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->rot_angle);
	*y = (*x + *y) * sin(data->rot_angle) - z;
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bbp / 8));
	*(unsigned int *)dst = color;
}

void	ft_zoomik_and_others(t_fdf *data, int *z, int *z1)
{
	*z = data->z_matrix[(int)data->cord.y][(int)data->cord.x];
	*z1 = data->z_matrix[(int)data->cord.y1][(int)data->cord.x1];
	data->cord.x *= data->zoom;
	data->cord.y *= data->zoom;
	data->cord.x1 *= data->zoom;
	data->cord.y1 *= data->zoom;
	data->color = color_f(*z, *z1);
}
