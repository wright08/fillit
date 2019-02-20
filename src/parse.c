/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:00:52 by rwright           #+#    #+#             */
/*   Updated: 2019/02/19 21:03:02 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
int		make_block(t_block *blocks, int i, char **raw_block)
{
	(void)blocks;
	(void)i;
	(void)raw_block;
	return (1);
}

int		parse(char *file, t_block *blocks, int *count)
{
	int		fd;
	int		j;
	char	*block[4];

	if (open(file, O_DIRECTORY) != -1 || (fd = open(file, O_RDONLY)) == -1)
		return (0);
	*count = 0;
	while (++(*count))
	{
		j = 0;
		while (j < 4 && get_next_line(fd, block + j) == 1)
			if (ft_strlen(block[j++]) != 4)
				return (0);
		if (j != 4 || !make_block(blocks, *count, block))
			return (0);
		if (*count == 26 || get_next_line(fd, block) < 1)
			break ;
		else if (ft_strcmp(block[0], "") != 0)
			return (0);
	}
	return (*count == 26 ? get_next_line(fd, block) < 1 : 1);
}

// 1. Check the file
// 2. Validate lines as they are read
// 3. Give back an array of t_block
//
// grab all four lines of what should be a block
