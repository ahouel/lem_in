/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:48:13 by ahouel            #+#    #+#             */
/*   Updated: 2017/06/06 15:00:54 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define debug(x) fprintf(stderr, "\x1B[31m%s\x1B[0m\n", x)
/*
**	Environment
*/

typedef struct	s_env
{
	int				nb_f;
	int				nb_fs;
	int				nb_c;
	int				x_max;
	int				y_max;
	char			**line;
	struct s_cell	**cell_lst;
}				t_env;

/*
**	Cells links
*/

typedef struct	s_link
{
	struct s_cell	*link;
	struct s_link	*next;
}				t_link;

/*
**	Cells
*/

typedef struct	s_cell
{
	char			type;
	char			*name;
	int				fourmie;
	int				dist;
	struct s_link	*link_lst;
	struct s_cell	*next;
}				t_cell;

int	resolver(t_env *e);
int	error_cell(t_env *e, char *line);
int	error_link(t_env *e, char *line);
int	cells_parser(t_env *e);
int	links_parser(t_env *e);
int	lem_in_init(void);
int	parser(t_env *e);
#endif
