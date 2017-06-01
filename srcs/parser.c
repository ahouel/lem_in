/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:30:37 by ahouel            #+#    #+#             */
/*   Updated: 2017/06/01 18:37:21 by ahouel           ###   ########.fr       */
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

static void diboug(t_env *e)
{
	t_cell *tmp;
	t_link	*tp;

	tmp = NULL;
	tmp = *e->cell_lst;
	while (tmp)
	{
		tp = tmp->link_lst;
		while (tp)
		{
			ft_printf("%{RED}p\n", tp);
			tp = tp->next;
		}
		tmp = tmp->next;
	}
}

static void deboug(t_env *e)
{
	t_cell *tmp;

	tmp = NULL;
	tmp = *e->cell_lst;
	while (tmp)
	{
	ft_printf("%{BLUE}p\t%{BLUE}s\n", tmp, tmp->name);
		tmp = tmp->next;
	}
}

int	parser(t_env *e)
{
	char	*line;
	int		ret;

	ret = 0;
	line = NULL;
	e->line = &line;
	get_next_line(0, &line);
	if (!line)
		return (-1);
	if (!(e->nb_f = get_nb_fourmies(line)))
		return (-2);
	if (!(e->nb_c = cells_parser(e)))
		return (-2);
	deboug(e);
	while ((ret = links_parser(e)) > 1)
		;
	debug("pata");
	diboug(e);
	//algo
	return (0);
}
