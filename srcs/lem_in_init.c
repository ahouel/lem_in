/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:54:25 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/30 15:29:31 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_vars(t_env *e, t_cell **cell)
{
	e->nb_f = 0;
	e->nb_c = 0;
	e->x_max = 0;
	e->y_max = 0;
	e->cell_lst = cell;
	*cell = NULL;
}

int	lem_in_init(void)
{
	t_env	e;
	t_cell	*cell;
	int		ret;

	ret = 0;
	init_vars(&e, &cell);
	if ((ret = parser(&e)) < 0)
		return (ret);
	return (ret);
}
