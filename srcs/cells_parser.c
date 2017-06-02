/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cells_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:23:22 by ahouel            #+#    #+#             */
/*   Updated: 2017/06/02 17:53:30 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_cell	*cell_new(void)
{
	t_cell	*new;

	new = NULL;
	if (!(new = (t_cell*)malloc(sizeof(t_cell))))
		return (NULL);
	new->type = ' ';
	new->fourmie = 'n';
	new->name = NULL;
	new->dist = -1;
	new->link_lst = NULL;
	new->next = NULL;
	return (new);
}

static int		cells_reader(t_env *e, char type)
{
	size_t	i;
	t_cell	*new;
	t_cell	*tmp;

	i = 0;
	new = NULL;
	tmp = NULL;
	if (!(new = cell_new()))
		return (0);
	while ((*e->line)[i] && (*e->line)[i] != ' ')
		++i;
	if (!(new->name = ft_strndup(*e->line, i)))
		return (0);
	new->type = type;
	tmp = *e->cell_lst;
	*e->cell_lst = new;
	new->next = tmp;
	return (1);
}

int				cells_parser(t_env *e)
{
	int		nb;
	char	type;

	nb = 0;
	while (get_next_line(0, e->line))
	{
		type = 'b';
		if (!(ft_strcmp(*e->line, "##start")))
		{
			type = 'a';
			get_next_line(0, e->line);
		}
		else if (!(ft_strcmp(*e->line, "##end")))
		{
			type = 'c';
			get_next_line(0, e->line);
		}
		if (!cells_reader(e, type))
			return (0);
		nb++;
		if (type == 'c')
		{
			e->nb_c = nb;
			return (1);
		}
	}
	return (1);
}
// gaffe aux relink si mauvais parse
