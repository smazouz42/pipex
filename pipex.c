/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:14:58 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/27 19:11:01 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *env[])
{
	char		**path;
	int			x;
	t_list		*command_lst;
	t_struct	fd;

	x = 0;
	if (!env[0])
		return (0);
	if (ac != 5)
		arc_error();
	else
	{
		path = ft_split(ft_find_path(env), ':');
		if (!path)
			ft_malloc_error(2, NULL, path);
		command_lst = make_list(path, ac, av);
		ft_parcer(ac, av, &command_lst);
		fd.out = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
		fd.in = open(av[1], O_RDWR);
		pipex((command_lst), env, &fd);
		ft_free_list(&command_lst);
	}
	return (0);
}
