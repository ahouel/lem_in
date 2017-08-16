/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 14:15:33 by ahouel            #+#    #+#             */
/*   Updated: 2017/06/24 14:17:00 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*link_new(void)
{
	t_link	*new;

	new = NULL;
	if (!(new = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	new->link = NULL;
	new->next = NULL;
	return (new);
}
