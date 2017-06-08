/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:10:08 by ahouel            #+#    #+#             */
/*   Updated: 2017/06/03 17:29:45 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	error_cell2(t_env *e, char *line)
{
	t_cell	*cell;
	size_t	i;

	i = 0;
	cell = *e->cell_lst;
	while (line[i] && line[i] != ' ')
		++i;
	while (cell)
	{
		if (!ft_strncmp(line, cell->name, i))
			return (0);
		cell = cell->next;
	}
//	debug("8");
	return (1);
}

int	error_cell(t_env *e, char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
//	debug("1");
	while (line[i] && line[i] != ' ')
	{
		if (!(ft_isprint(line[i++])))
			return (0);
	}
//	debug("2");
	if (!line[i])
		return (0);
//	debug("3");
	++i;
	if (!ft_isdigit(line[i]))
		return (0);
//	debug("4");
	while (line[i] && ft_isdigit(line[i]))
		++i;
	if (line[i] != ' ')
		return (0);
//	debug("5");
	++i;
	if (!ft_isdigit(line[i]))
		return (0);
	++i;
//	debug("6");
	while (line[i])
		if (!ft_isdigit(line[i]))
			return (0);
//	debug("7");
	return (error_cell2(e, line));
}
