/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:10:08 by ahouel            #+#    #+#             */
/*   Updated: 2017/08/07 16:44:34 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	error_cell2(t_env *e, char *line)
{
	t_cell	*cell;
	size_t	i;

	i = 0;
	cell = *e->cell_lst;
	if (ft_strchr(line, '-'))
		return (0);
	while (line[i] && line[i] != ' ')
		++i;
	while (cell)
	{
		if (!ft_strncmp(line, cell->name, i) && i == ft_strlen(cell->name))
			return (0);
		cell = cell->next;
	}
	return (1);
}

int			error_cell(t_env *e, char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != ' ')
		if (!(ft_isprint(line[i++])))
			return (0);
	if (!line[i])
		return (0);
	++i;
	if (!ft_isdigit(line[i]))
		return (0);
	while (line[i] && ft_isdigit(line[i]))
		++i;
	if (line[i] != ' ')
		return (0);
	++i;
	if (!ft_isdigit(line[i]))
		return (0);
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (0);
	return (error_cell2(e, line));
}
