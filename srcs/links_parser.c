/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:28:19 by ahouel            #+#    #+#             */
/*   Updated: 2017/07/30 15:36:14 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	links_checker(t_cell *c1, t_cell *c2)
{
	t_link	*link;

	link = c1->link_lst;
	while (link)
	{
		if (link->link == c2)
			return (0);
		link = link->next;
	}
	link = c2->link_lst;
	while (link)
	{
		if (link->link == c1)
			return (0);
		link = link->next;
	}
	return (1);
}

static int	links_maker(t_cell *c1, t_cell *c2)
{
	t_link	*tmp;
	t_link	*new;

	if (!links_checker(c1, c2))
		return (2);
	new = NULL;
	tmp = NULL;
	if (!(new = link_new()))
		return (0);
	tmp = c1->link_lst;
	c1->link_lst = new;
	new->link = c2;
	new->next = tmp;
	new = NULL;
	tmp = NULL;
	if (!(new = link_new()))
		return (0);
	tmp = c2->link_lst;
	c2->link_lst = new;
	new->next = tmp;
	new->link = c1;
	return (2);
}

int			links_parser(t_env *e, char **line)
{
	t_cell	*cell1;
	t_cell	*cell2;
	size_t	i;

	i = 0;
	if (!error_link(e, *line))
		return (0);
	cell1 = NULL;
	cell2 = *e->cell_lst;
	if (!ft_strchr(*line, '-'))
		return (0);
	while ((*line)[i] != '-')
		i++;
	while (cell2)
	{
		if (!ft_strncmp(*line, cell2->name, i) ||
				!ft_strcmp((*line) + i + 1, cell2->name))
		{
			if (cell1)
				return (links_maker(cell1, cell2));
			cell1 = cell2;
		}
		cell2 = cell2->next;
	}
	return (0);
}
