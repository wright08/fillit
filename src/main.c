/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <rwright@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:59:03 by rwright           #+#    #+#             */
/*   Updated: 2019/02/22 17:24:31 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_block arr[26];
	int		count;

	if (argc != 2)
	{
		ft_putendl_fd("usage: fillit file", 2);
		exit(EXIT_FAILURE);
	}
	else if (!parse(argv[1], arr, &count))
	{
		ft_putendl("Error");
		exit(EXIT_FAILURE);
	}
	fillit(arr, count);
	exit(EXIT_SUCCESS);
}
