/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 15:15:32 by ahouel            #+#    #+#             */
/*   Updated: 2017/06/08 19:23:00 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	algo(t_env *e, t_cell *cell, int dist)
{
	t_link	*link;
	int		ret;

	ret = 0;
	link = cell->link_lst;
	cell->dist = dist;
	//	if (dist <= e->nb_fs)
	//	{
	while (link)
	{
	//	ft_printf("cell %s\tlink : %s\n", cell->name, link->link->name);
	//	printf("link dist %d, dist %d\n", link->link->dist, dist);
		if (cell->type != 'a')
			if (link->link->dist > dist || link->link->dist == -1)
			{
				if (link->link->fourmie > 0 && (cell->fourmie == 0 || cell->type == 'c'))
				{
					ft_printf("%s prend a %s\n", cell->name, link->link->name);
					cell->fourmie++;
					link->link->fourmie--;
					link->link->type == 'a' ? (e->nb_fs--) : 0;
					ret += 1;
				}
				ret += algo(e, link->link, dist + 1);
			}
		link = link->next;
	}
	//	}
	cell->dist = -1;
	return (ret);
}
static void testy(t_env *e)
{
	t_cell *cell;

	cell = NULL;
	cell = *e->cell_lst;
	debug("PASSAGE SOUS ALGO");
	while (cell)
	{
		ft_printf("%s a %d fourmie\n", cell->name, cell->fourmie);
		cell = cell->next;
	}

}

int	resolver(t_env *e)
{
	t_cell	*cell;
	t_cell *celltst;
	int		i;

	i = 0;

	cell = NULL;
	celltst = NULL;
	cell = *e->cell_lst;
	debug("RESOLVER");
	//	while (cell)
	//	{
	//		if (!ft_strcmp(cell->name, "toto"))
	//			ft_printf("%{CYAN}c\n", cell->type);
	//		if (!ft_strcmp(cell->name, "tete"))
	//			cell->dist = 1;
	//		if (!ft_strcmp(cell->name, "tata"))
	//			cell->fourmie = 1;
	//		if (!ft_strcmp(cell->name, "tutu"))
	//			cell->dist = 10;
	//		if (!ft_strcmp(cell->name, "titi"))
	//			cell->fourmie = 1;
	//		cell = cell->next;
	//	}
	cell = *e->cell_lst;
	while (cell)
	{
		if (cell->type == 'c')
		{
			celltst = cell;
			e->nb_fs = 10;
			ft_printf("%{BLUE}s\n", cell->name);
			break ;
		}
		cell = cell->next;
	}
	while (++i < 8)
	{
		algo(e, cell, 0);
		testy(e);
	}
	return (1);
}
