/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 19:44:38 by ahouel            #+#    #+#             */
/*   Updated: 2017/08/07 19:58:52 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	sort_links(t_cell *cell)
{
	t_link	*link;
	t_cell	*tmp;

	tmp = NULL;
	link = cell->link_lst;
	while (link)
	{
		if (link->next)
		{
			if (link->link->dst > link->next->link->dst)
			{
				tmp = link->link;
				link->link = link->next->link;
				link->next->link = tmp;
				link = cell->link_lst;
			}
			else
				link = link->next;
		}
		else
			link = link->next;
	}
}
