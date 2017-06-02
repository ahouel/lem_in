/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:28:19 by ahouel            #+#    #+#             */
/*   Updated: 2017/06/02 18:09:14 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_link	*link_new(void)
{
	t_link	*new;

	new = NULL;
	if (!(new = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	new->link = NULL;
	new->next = NULL;
	return (new);
}

static int	links_maker(t_cell *c1, t_cell *c2)
{
	t_link	*tmp;
	t_link	*new;

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
	return (1);
}

int	links_parser(t_env *e)
{
	t_cell	*cell1;
	t_cell	*cell2;
	char	*c1;
	char	*c2;

	debug("c");
	//p-e init c1 c2 cell1 cell2 // a voir
	c1 = NULL;
	c2 = NULL;
	get_next_line(0, e->line);
	cell1 = NULL;
	cell2 = *e->cell_lst;
	c1 = *e->line;
	c2 = ft_strchr(*e->line, '-');
	if (!c2)
		return (0);
	c2++;
	debug("d");
	ft_printf("%s\t%s\n", c1, c2);
	while (cell2)
	{
		ft_printf("e %{RED}s\n", cell2->name);
		if (ft_strstr(c1, cell2->name) == c1)
		{
			if (!cell1)
				cell1 = cell2;
			else
			{
		ft_printf("linking : %{RED}s\t%{RED}s\n", cell2->name, cell1->name);
				return (links_maker(cell1, cell2));
			}
		}
		else if (ft_strstr(c2, cell2->name) == c2)
		{
			if (!cell1)
				cell1 = cell2;
			else
			{
		ft_printf("linking : %{RED}s\t%{RED}s\n", cell2->name, cell1->name);
				return (links_maker(cell1, cell2));
			}

		}
		cell2 = cell2->next;
	}
	return (0);
}
