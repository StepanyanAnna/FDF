/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:45:55 by annstepa          #+#    #+#             */
/*   Updated: 2022/11/03 21:06:14 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# define K_ESC 53
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_Z 6
# define K_X 7
# define K_UP 126
# define K_DOWN 125
# define K_RIGHT 124
# define K_LEFT 123
# define WIN_H 1080
# define WIN_W 1920

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bbp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_cord
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}			t_cord;

typedef struct s_fdf
{
	t_img	image;
	t_cord	cord;
	int		width;
	int		heigth;
	int		color;
	int		zoom;
	int		shift_x;
	int		shift_y;
	int		**z_matrix;
	float	rot_angle;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;

float	mod_f(float x);
int		esc(t_fdf *data);
void	draw(t_fdf *data);
int		ft_frame(t_fdf *data);
void	ft_clear(t_fdf *data);
void	bresenham(t_fdf *data);
char	*get_next_line(int fd);
int		color_f(int z, int z1);
float	max_f(float x, float y);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	map_check(char *file_name);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		deal_key(int key, t_fdf *data);
void	ft_move(t_fdf *data, int key_code);
int		key_pressed(int key_code, t_fdf *data);
void	read_file(char *file_name, t_fdf *data);
char	**ft_split(const char *string, char del);
size_t	count_of_words(const char *string, char del);
int		key_pressed_bonus(int key_code, t_fdf *data);
void	isometric(float *x, float *y, int z, t_fdf *data);
void	ft_zoomik_and_others(t_fdf *data, int *z, int *z1);
char	**fill_string(char **store, const char *s, char del);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_steps(t_fdf *data, float *step_x, float *step_y, float *max);

#endif
