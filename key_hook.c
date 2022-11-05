/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:46:21 by annstepa          #+#    #+#             */
/*   Updated: 2022/11/03 20:46:24 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(t_fdf *data, int key_code)
{
	if (key_code == K_W || key_code == K_UP)
		data->shift_y -= 15;
	if (key_code == K_S || key_code == K_DOWN)
		data->shift_y += 15;
	if (key_code == K_D || key_code == K_RIGHT)
		data->shift_x += 15;
	if (key_code == K_A || key_code == K_LEFT)
		data->shift_x -= 15;
}

int	esc(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->heigth)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	exit(0);
	return (0);
}

void	ft_clear(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			my_mlx_pixel_put(&data->image, j, i, 0x0000000);
			++j;
		}
		++i;
	}
}

int	ft_frame(t_fdf *data)
{
	ft_clear(data);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->image.img, 0, 0);
	mlx_do_sync(data->mlx_ptr);
	return (1);
}
