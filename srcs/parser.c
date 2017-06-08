/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:30:37 by ahouel            #+#    #+#             */
/*   Updated: 2017/06/08 15:08:54 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void diboug(t_env *e)
{
	t_cell *tmp;
	t_link	*tp;

	tmp = NULL;
	tmp = *e->cell_lst;
	while (tmp)
	{
		ft_printf("%{RED}s%{RED}s\n", "test dans\t", tmp->name);
		tp = tmp->link_lst;
		while (tp)
		{
			ft_printf("%{RED}s%{BLUE}s\n", "link vers\t", tp->link->name);
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
	get_next_line(0, &line); // FREEEEEEEEEEEE
	if (!line)
		return (-1);
	if ((e->nb_f = ft_atoi(line)) < 1)
	{
		e->nb_fs = e->nb_f;
		debug("fourmie fail");
		return (-2);
	}
	if (!(e->nb_c = cells_parser(e)))
	{
		debug("cell fail");
		return (-2);
	}
	deboug(e);
	while ((ret = links_parser(e)) > 0)
	{
		ft_printf("ret : %d\n", ret);
	}
	debug("pata");
	diboug(e);
	ret = resolver(e);
	return (ret);
}
