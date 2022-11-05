/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:45:42 by annstepa          #+#    #+#             */
/*   Updated: 2022/11/03 20:45:45 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_shifting(t_fdf *data)
{
	data->cord.x += data->shift_x;
	data->cord.y += data->shift_y;
	data->cord.x1 += data->shift_x;
	data->cord.y1 += data->shift_y;
}

int	color_f(int z, int z1)
{
	if (z || z1)
		return (0xe80c0c);
	return (0xffffff);
}

void	bresenham(t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	max;
	int		z;
	int		z1;

	ft_zoomik_and_others(data, &z, &z1);
	isometric(&data->cord.x, &data->cord.y, z, data);
	isometric(&data->cord.x1, &data->cord.y1, z1, data);
	ft_shifting(data);
	ft_steps(data, &x_step, &y_step, &max);
	while ((int)(data->cord.x1 - data->cord.x) ||
		(int)(data->cord.y1 - data->cord.y))
	{
		if ((data->cord.y < WIN_H) && (data->cord.x < WIN_W))
		{
			if (data->cord.x >= 0 && data->cord.y >= 0)
				my_mlx_pixel_put(&data->image, data->cord.x, data->cord.y,
					data->color);
		}
		data->cord.x += x_step;
		data->cord.y += y_step;
	}
}

void	init_cord(t_fdf *data, int x, int y, int a)
{
	if (a == 1)
	{
		data->cord.x = x;
		data->cord.x1 = x + 1;
		data->cord.y = y;
		data->cord.y1 = y;
	}
	else if (a == 2)
	{
		data->cord.x = x;
		data->cord.x1 = x;
		data->cord.y = y;
		data->cord.y1 = y + 1;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->heigth)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				init_cord(data, x, y, 1);
				bresenham(data);
			}
			if (y < data->heigth - 1)
			{
				init_cord(data, x, y, 2);
				bresenham(data);
			}
			x++;
		}
		y++;
	}
}
