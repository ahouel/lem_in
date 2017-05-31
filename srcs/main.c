/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:49:02 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/30 15:21:43 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	usage(void)
{
	ft_putstr("Usage : ./lem_in | file.map");
}

int	main(int ac, char **av)
{
	int	ret;

	ret = 0;
	if (ac != 1)
	{
		usage();
		return (ret);
	}
	ret = lem_in_init();
	if (av)
		return (ac);
	return (ret);
}