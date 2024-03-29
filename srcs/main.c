/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:49:02 by ahouel            #+#    #+#             */
/*   Updated: 2017/08/08 17:31:43 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	usage(void)
{
	ft_printf("Usage : ./lem_in < file.map\n");
}

int			main(int ac, char **av)
{
	int	ret;

	ret = 0;
	if (ac != 1 || !av)
	{
		usage();
		return (ret);
	}
	ret = lem_in_init();
	if (ret < 0)
		ft_putstr("ERROR\n");
	return (ret);
}
