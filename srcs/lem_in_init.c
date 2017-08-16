/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:54:25 by ahouel            #+#    #+#             */
/*   Updated: 2017/08/07 19:53:30 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_vars(t_env *e, t_cell **cell)
{
	e->nb_f = 0;
	e->cell_lst = cell;
	*cell = NULL;
	e->f_tab = NULL;
}

static void	free_all(t_env *e)
{
	t_cell	*cell;
	t_cell	*tmp_c;
	t_link	*link;
	t_link	*tmp_l;

	cell = *e->cell_lst;
	ft_memdel((void**)&e->f_tab);
	while (cell)
	{
		link = cell->link_lst;
		while (link)
		{
			tmp_l = link;
			link = link->next;
			ft_memdel((void**)&tmp_l);
		}
		ft_memdel((void**)&cell->name);
		tmp_c = cell;
		cell = cell->next;
		ft_memdel((void**)&tmp_c);
	}
}

int			lem_in_init(void)
{
	t_env	e;
	t_cell	*cell;
	int		ret;

	ret = 0;
	init_vars(&e, &cell);
	if ((ret = parser(&e)) < 0)
		return (ret);
	ret = resolver(&e);
	free_all(&e);
	return (ret);
}
