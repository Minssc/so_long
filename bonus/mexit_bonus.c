/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mexit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 01:20:17 by minsunki          #+#    #+#             */
/*   Updated: 2022/02/23 01:20:17 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mexit(int ec)
{
	meta_destroy();
	exit(ec);
}

void	perror_exit(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	if (str[ft_strlen(str) - 1] != '\n')
		ft_putchar_fd('\n', 2);
	mexit(1);
}
