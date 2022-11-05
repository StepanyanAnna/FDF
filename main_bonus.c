/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:46:44 by annstepa          #+#    #+#             */
/*   Updated: 2022/11/03 20:46:46 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac == 1 || ac > 2)
	{
		write(1, "ERROR!\n", 7);
		exit(0);
	}
	data = (t_fdf *)malloc(sizeof (t_fdf));
	read_file(av[1], data);
	data->zoom = 20;
	data->rot_angle = 0.8;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "FDF");
	data->image.img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bbp,
			&data->image.line_len, &data->image.endian);
	mlx_loop_hook(data->mlx_ptr, ft_frame, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, esc, data);
	mlx_hook(data->win_ptr, 2, 0, key_pressed_bonus, data);
	mlx_loop(data->mlx_ptr);
}
