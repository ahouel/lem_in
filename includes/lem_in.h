/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:48:13 by ahouel            #+#    #+#             */
/*   Updated: 2017/08/16 19:48:46 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define CHEAT 1

/*
**	Environment
*/

typedef struct	s_env
{
	int					nb_f;
	int					cheat;
	struct s_fourmie	*f_tab;
	struct s_cell		**cell_lst;
}				t_env;

/*
** Fourmies
*/

typedef struct	s_fourmie
{
	int				nb;
	struct s_cell	*cell;
}				t_fourmie;

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
	int				dst;
	struct s_link	*link_lst;
	struct s_cell	*next;
}				t_cell;

void			sort_links(t_cell *cell);
int				reader(t_env *e, char **line, int check, char type);
t_link			*link_new(void);
int				calc_dist(t_env *e, t_cell *end, int dst);
int				resolver(t_env *e);
int				error_cell(t_env *e, char *line);
int				error_link(t_env *e, char *line);
int				cells_parser(t_env *e, char type, char **line);
int				links_parser(t_env *e, char **line);
int				lem_in_init(void);
int				parser(t_env *e);
#endif
