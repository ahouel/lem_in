/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:17:11 by ahouel            #+#    #+#             */
/*   Updated: 2017/07/30 15:36:16 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	if (line[i] != '-')
		return (0);
	while (cell)
	{
		!ft_strncmp(line, cell->name, i) ? c1 = cell : 0;
		!ft_strcmp(line + i + 1, cell->name) ? c2 = cell : 0;
		cell = cell->next;
	}
	if (c1 == c2 || !c1 || !c2)
		return (0);
	return (1);
}
