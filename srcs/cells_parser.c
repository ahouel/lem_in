/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cells_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:23:22 by ahouel            #+#    #+#             */
/*   Updated: 2017/07/27 05:52:22 by ahouel           ###   ########.fr       */
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
	new->fourmie = 0;
	new->name = NULL;
	new->dst = -1;
	new->link_lst = NULL;
	new->next = NULL;
	return (new);
}

static int		cells_reader(t_env *e, char type, char **line)
{
	size_t	i;
	t_cell	*new;
	t_cell	*tmp;

	i = 0;
	new = NULL;
	tmp = NULL;
	if (!(new = cell_new()))
		return (0);
	while ((*line)[i] && (*line)[i] != ' ')
		++i;
	if (!(new->name = ft_strndup(*line, i)))
		return (0);
	new->type = type;
	type == 'a' ? (new->fourmie = e->nb_f) : 0;
	tmp = *e->cell_lst;
	*e->cell_lst = new;
	new->next = tmp;
	return (1);
}

int				cells_parser(t_env *e, char type, char **line)
{
	if (!error_cell(e, *line))
		return (2);
	if (!cells_reader(e, type, line))
		return (-1);
	return (1);
}
