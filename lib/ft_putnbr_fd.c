/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:08:52 by rwright           #+#    #+#             */
/*   Updated: 2019/01/30 20:11:11 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long overflow;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		overflow = n;
		if (n < -9)
			ft_putnbr_fd(-overflow / 10, fd);
		ft_putchar_fd(-overflow % 10 + '0', fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
