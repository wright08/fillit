/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <rwright@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:00:46 by rwright           #+#    #+#             */
/*   Updated: 2019/02/21 15:57:27 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

t_block	settle(t_block block)
{
	int		i;
	int		up;
	int		left;
	int		tmp;
	t_block	new;

	up = 3;
	left = 3;
	i = -1;
	while (++i < 4)
	{
		if ((tmp = (block >> (i * 4)) % 4) < left)
			left = tmp;
		if ((tmp = (block >> (i * 4)) / 4) < up)
			up = tmp;
	}
	i = -1;
	new = 0;
	while (++i < 4)
	{
		new = (new << 4) + ((block >> (4 * (3 - i))) % 16) - 4 * up - left;
	}
	return (new);
}

int		validate(t_block *block)
{
	int				i;
	static t_block	valids[] = {1112, 5209, 328, 345, 1161, 5513, 5208, 1113,
		325, 291, 1164, 293, 5206, 294, 292, 9302, 1110, 4677, 342};

	*block = settle(*block);
	i = -1;
	while (++i < 19)
		if (*block == valids[i])
			return (1);
	return (0);
}

int		make_block(t_block *arr, int index, char **raw_block)
{
	int i;
	int j;
	int cell_count;

	cell_count = 0;
	ft_bzero(arr + index, sizeof(t_block));
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (raw_block[i][j] == '#')
			{
				if (cell_count++ == 4)
					return (0);
				arr[index] = (arr[index] << 4) + (4 * i + j);
			}
			else if (raw_block[i][j] != '.')
				return (0);
		}
	}
	return (cell_count == 4 && validate(arr + index));
}

void	free_stuff(char *block[4], int n)
{
	while (n--)
		free(block[n]);
}

int		parse(char *file, t_block *arr, int *count)
{
	int		fd;
	int		j;
	char	*block[4];
	int		status;

	if (open(file, O_DIRECTORY) != -1 || (fd = open(file, O_RDONLY)) == -1)
		return (0);
	*count = 0;
	while (++(*count))
	{
		j = 0;
		while (j < 4 && get_next_line(fd, block + j) == 1)
			if (ft_strlen(block[j++]) != 4)
				return (0);
		if (j != 4 || !make_block(arr, *count - 1, block))
			return (0);
		free_stuff(block, 4);
		if (*count == 26 || (status = get_next_line(fd, block)) < 1)
			break ;
		else if (ft_strcmp(block[0], "") != 0)
			return (0);
		free_stuff(block, 1);
	}
	return (*count == 26 ? get_next_line(fd, block) == 0 : status == 0);
}
