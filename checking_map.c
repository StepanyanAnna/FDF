/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:45:16 by annstepa          #+#    #+#             */
/*   Updated: 2022/11/03 20:45:18 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_check(char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 1);
	line = get_next_line(fd);
	while (line)
	{
		if (line[1] == '\0')
		{
			ft_putstr_fd("Map isn't valid, somthing wrong in this map!", 1);
			exit(0);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}
