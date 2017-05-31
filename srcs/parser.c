/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:30:37 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/30 17:19:37 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_nb_fourmies(char *line)
{
	int	i;

	i = -1;
	while (line[i])
		if (!ft_isdigit(line[i]))
			return (0);
	return (ft_atoi(line));
}

static int	cells_reader(t_env *e, char type)
{
	size_t	i;
	t_cell	cell;

	i = 0;
	if (!(ft_lstnew((void*)&cell, sizeof(cell))))
		return (0);
	ft_lstadd((t_list**)e->cell_lst, (t_list*)&cell);
	while ((*e->line)[i] && (*e->line)[i] != ' ')
		++i;
	if (!(cell.name = ft_strndup(*e->line, i)))
		return (0);
	cell.type = type;
	cell.fourmie = n;
	cell.dist = -1;
	return (1);
}

static int	get_cells(t_env *e)
{
	int		nb;

	nb = 0;
	while (get_next_line(0, e->line))
	{
		type = 1;
		if (!(ft_strcmp(*e->line, "##start")))
		{
			type = 0;
			get_next_line(0, e->line);
		}
		else if (!(ft_strcmp(*e->line, "##end")))
		{
			type = 2;
			get_next_line(0, e->line);
		}
		if (!cells_reader(e))
			return (-1);
	}
}

int	parser(t_env *e)
{
	char	*line;

	line = NULL;
	e->line = &line;
	get_next_line(0, &line);
	if (!line)
		return (-1);
	if ((e->nb_f = get_nb_fourmies(line)) < 1)
		return (-2);
	if ((e->nb_c = get_cells(e)) < 1)
		return (-2);
	if (get_links(e) < 1)
		return (-2);
	//algo
	return (0);
}
