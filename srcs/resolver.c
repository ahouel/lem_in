/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 15:15:32 by ahouel            #+#    #+#             */
/*   Updated: 2017/08/07 19:58:10 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	move_fourmie(t_env *e, int nb, t_link **link, int *ret)
{
	*ret ? ft_putchar(' ') : 0;
	if (e->f_tab[nb].cell->type == 'a')
		e->f_tab[nb].cell->fourmie--;
	ft_printf("L%d-%s", e->f_tab[nb].nb, (*link)->link->name);
	(*link)->link->fourmie++;
	e->f_tab[nb].cell = (*link)->link;
	*link = NULL;
	(*ret)++;
}

static int	tester(t_env *e, t_link *link, int nb, int min)
{
	if (link->link->dst != -1 && link->link->type != 'a' &&
			(link->link->fourmie == 0 || link->link->type == 'c')
			&& (link->link->dst < e->f_tab[nb].cell->dst ||
			(e->f_tab[nb].cell->type == 'a' && link->link->dst <
			min + e->f_tab[nb].cell->fourmie)))
		return (1);
	return (0);
}

static int	algo(t_env *e, int min)
{
	int		nb;
	int		ret;
	t_link	*link;

	ret = 0;
	e->cheat = 0;
	nb = -1;
	while (++nb < e->nb_f)
	{
		link = e->f_tab[nb].cell->link_lst;
		while (link)
		{
			if (tester(e, link, nb, min) && ((e->f_tab[nb].cell->type != 'a' ||
							link->link->type != 'c') || e->cheat == 0))
			{
				if (e->f_tab[nb].cell->type == 'a' && link->link->type == 'c'
						&& e->cheat == 0 && CHEAT == 0)
					e->cheat = 1;
				move_fourmie(e, nb, &link, &ret);
			}
			else
				link = link->next;
		}
	}
	return (ret);
}

static int	resolver2(t_env *e, t_link *link)
{
	int		min_dst;
	t_cell	*cell;

	min_dst = -1;
	while (link)
	{
		if (min_dst == -1 || (link->link->dst < min_dst &&
					link->link->dst > -1))
			min_dst = link->link->dst;
		link = link->next;
	}
	while (algo(e, min_dst))
	{
		ft_putchar('\n');
		cell = *e->cell_lst;
		while (cell)
		{
			if (cell->type == 'b')
				cell->fourmie = 0;
			cell = cell->next;
		}
	}
	return (1);
}

int			resolver(t_env *e)
{
	t_cell	*cell;

	cell = *e->cell_lst;
	while (cell)
	{
		if (cell->type == 'c')
			break ;
		cell = cell->next;
	}
	if (!cell || !calc_dist(e, cell, 0))
		return (-1);
	cell = *e->cell_lst;
	while (cell)
	{
		if (cell->type == 'a')
			break ;
		cell = cell->next;
	}
	sort_links(cell);
	return (resolver2(e, cell->link_lst));
}
