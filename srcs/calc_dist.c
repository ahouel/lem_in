/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 01:08:34 by ahouel            #+#    #+#             */
/*   Updated: 2017/07/27 05:38:43 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	calc_dist(t_env *e, t_cell *end, int dst)
{
	t_link	*link;
	t_cell	*cell;
	int		ret;

	ret = 0;
	cell = end;
	if (cell->type == 'a')
	{
		cell->dst = 0;
		return (1);
	}
	cell->dst = dst++;
	link = cell->link_lst;
	while (link)
	{
		if (link->link->dst == -1 || link->link->dst > dst)
			ret += calc_dist(e, link->link, dst);
		link = link->next;
	}
	return (ret);
}
