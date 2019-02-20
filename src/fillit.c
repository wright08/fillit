/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:02:24 by rwright           #+#    #+#             */
/*   Updated: 2019/02/19 16:46:36 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	display_usage()
{
	ft_putendl_fd("usage: fillit file", 2);
	exit(EXIT_FAILURE);
}

void	fillit(char *file)
{
	t_block *blocks;

	if (!parse(file, &blocks))
		exit(EXIT_FAILURE);
	ft_putendl("Parse successful");
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		display_usage();
	fillit(argv[1]);
	exit(EXIT_SUCCESS);
}
