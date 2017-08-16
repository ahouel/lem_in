/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 16:38:33 by ahouel            #+#    #+#             */
/*   Updated: 2017/08/07 19:03:44 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	reader3(t_env *e, char **line, int *check, char type)
{
	if (*check == 1 && type < 'd')
		if ((*check = cells_parser(e, type, line)) < 0)
			return (0);
	if (*check == 2)
	{
		if (type == 'b')
		{
			if ((*check = links_parser(e, line)) < 0)
				return (0);
		}
		else
			return (0);
	}
	if (type > 'c')
	{
		type == 'y' ? ft_printf("Can't use this command twice\n") : 0;
		type == 'z' ? ft_printf("Unknown command\n") : 0;
		return (0);
	}
	return (1);
}

static int	reader2(t_env *e, char **line, int check, char type)
{
	while (*line && ft_strncmp(*line, "##", 2) && !ft_strncmp(*line, "#", 1))
	{
		ft_printf("%s\n", *line);
		*line ? ft_memdel((void**)line) : 0;
		get_next_line(0, line);
	}
	if (!(*line))
	{
		type != 'b' ? reader3(e, line, (int*)&type, type) : 0;
		return (0);
	}
	if (!ft_strncmp(*line, "##", 2))
		return (reader(e, line, check, type));
	if (ft_strncmp(*line, "L", 1))
	{
		if (!reader3(e, line, &check, type))
			return (-1);
	}
	else
		return (0);
	return (check);
}

static int	type_checker(t_env *e, char type)
{
	t_cell	*cell;

	cell = *e->cell_lst;
	while (cell)
	{
		if (cell->type == type)
			return (0);
		cell = cell->next;
	}
	return (1);
}

int			reader(t_env *e, char **line, int check, char type)
{
	if (!(ft_strncmp(*line, "##", 2)))
	{
		if (type != 'b')
			return (reader3(e, line, &check, type));
		if (!ft_strcmp(*line + 2, "start"))
		{
			type = 'y';
			if (type_checker(e, 'a'))
				type = 'a';
		}
		else if (!ft_strcmp(*line + 2, "end"))
		{
			type = 'y';
			if (type_checker(e, 'c'))
				type = 'c';
		}
		else
			type = 'z';
		ft_printf("%s\n", *line);
		*line ? ft_memdel((void**)line) : 0;
		get_next_line(0, line);
	}
	return (reader2(e, line, check, type));
}
