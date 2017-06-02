/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:17:11 by ahouel            #+#    #+#             */
/*   Updated: 2017/06/02 18:09:15 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	error_link2(t_env *e, t_cell *c1, t_cell *c2)
{
	t_cell	*cell;
	t_link	*link;

	cell = *e->cell_lst;
	while (cell)
	{
		link = cell->link_lst;
		while (link)
		{
			if (link->link == c1 || link->link == c2)
				return (0);
			link = link->next;
		}
		cell = cell->next;
	}
	return (1);
}

int	error_link(t_env *e, char *line)
{
	size_t	i;
	t_cell	*cell;
	t_cell	*c1;
	t_cell	*c2;

	i = 0;
	c1 = NULL;
	c2 = NULL;
	cell = *e->cell_lst;
	if (!line)
		return (0);
	while (line[i] && line[i] != '-')
		++i;
	while (cell)
	{
		if (!ft_strncmp(line, cell->name, i))
		{
			if (c1)
				return (0);
			c1 = cell;
		}
		cell = cell->next;
	}
	if (line[i] != '-')
		return (0);
	cell = *e->cell_lst;
	nb = 0;
	while (cell)
	{
		if (!ft_strcmp(line + i + 1, cell->name))
		{
			if (c2)
				return (0);
			c2 = cell;
		}
		cell = cell->next;
	}
	if (c1 == c2)
		return (0);
	return (error_link2(t_env *e, c1, c2));
}
