/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:30:37 by ahouel            #+#    #+#             */
/*   Updated: 2017/08/08 17:28:20 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	fourmie_maker(t_env *e)
{
	t_fourmie	*tab;
	int			i;
	t_cell		*cell;

	tab = NULL;
	i = -1;
	cell = *e->cell_lst;
	while (cell)
	{
		if (cell->type == 'a')
			break ;
		else
			cell = cell->next;
	}
	if (!(tab = (t_fourmie*)malloc(sizeof(t_fourmie) * e->nb_f + 1)))
		return (0);
	while (++i < e->nb_f)
	{
		tab[i].nb = i + 1;
		tab[i].cell = cell;
	}
	e->f_tab = tab;
	return (1);
}

int			parser(t_env *e)
{
	char	*line;
	int		ret;

	ret = 1;
	line = NULL;
	get_next_line(0, &line);
	if (!line || (e->nb_f = ft_atoi(line)) < 1)
		return (-1);
	ft_printf("%s\n", line);
	ft_printf("bipbip\n");
	line ? ft_memdel((void**)&line) : 0;
	while (get_next_line(0, &line))
	{
		ret = reader(e, &line, ret, 'b');
		if (ret < 0)
			return (ret);
		else if (!ret)
			break ;
		ft_printf("%s\n", line);
		line ? ft_memdel((void**)&line) : 0;
	}
	line ? ft_memdel((void**)&line) : 0;
	if (!fourmie_maker(e))
		return (-2);
	ft_putchar('\n');
	return (ret);
}
