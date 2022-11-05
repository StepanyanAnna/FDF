/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:47:11 by annstepa          #+#    #+#             */
/*   Updated: 2022/11/03 21:07:07 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_heigth(char *file_name)
{
	int		fd;
	int		heigth;
	char	*line;

	heigth = 0;
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line)
	{
		++heigth;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (heigth);
}

int	get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = count_of_words(line, ' ');
	if (width == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *data, char *line)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = ft_split(line, ' ');
	while (matrix[i])
	{
		data[i] = ft_atoi(matrix[i]);
		free(matrix[i]);
		++i;
	}
	free(matrix);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		ft_error("Error!");
	data->heigth = get_heigth(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->heigth + 1));
	while (i < data->heigth)
		data->z_matrix[i++] = (int *) malloc(sizeof(int *) * (data->width));
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		line = get_next_line(fd);
		++i;
	}
	close(fd);
	data->z_matrix[i] = 0;
}
