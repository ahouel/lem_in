/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:17:11 by ahouel            #+#    #+#             */
/*   Updated: 2017/06/05 16:42:37 by ahouel           ###   ########.fr       */
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
		debug("7");
		debug(cell->name);
		if (cell == c1 || cell == c2)
		{
			link = cell->link_lst;
			while (link)
			{
				if (link->link == c1 || link->link == c2)
				{
					fprintf(stderr, "ON A UN SOUCIS\nlink : %p, c1 : %p, c2 : %p\n", link->link, c1, c2);
					fprintf(stderr, "EWI\nlink : %s, c1 : %s, c2 : %s\n", link->link->name, c1->name, c2->name);
					return (0);
				}
				link = link->next;
			}
		}
		cell = cell->next;
	}
	debug("8");
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
	debug("1");
	debug(line);
	if (!line)
		return (0);
	while (line[i] && line[i] != '-')
		++i;
	debug("2");
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
	debug("3");
	if (line[i] != '-')
		return (0);
	cell = *e->cell_lst;
	debug("4");
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
	debug("5");
	if (c1 == c2)
		return (0);
	debug("6");
	fprintf(stderr, "%p\n", c1);
	fprintf(stderr, "%p\n", c2);
	return (error_link2(e, c1, c2));
}
