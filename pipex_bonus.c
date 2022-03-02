/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:55:09 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/27 18:46:57 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

static void	here_doc_pipe(char **env, char **av, int ac)
{
	t_struct	fd;
	int			fd_tmp;
	char		**path;
	t_list		*command_lst;

	path = ft_split(ft_find_path(env, "PATH"), ':');
	if (!path)
		ft_malloc_error(2, NULL, path);
	command_lst = make_list(path, ac, av, 3);
	ft_parcer(ac, av, &command_lst, 3);
	fd.out = open(av[ac - 1], O_RDWR | O_CREAT, 0777);
	fd_tmp = open("temp", O_RDWR | O_CREAT | O_TRUNC, 0777);
	read_from_here_doc(&command_lst, fd_tmp, av[2], env);
	close(fd_tmp);
	fd.in = open("temp", O_RDONLY);
	pipex((command_lst), env, &fd);
	ft_free_list(&command_lst);
}

static void	multiple_pipe(char **env, char **av, int ac)
{
	char		**path;
	t_list		*command_lst;
	t_struct	fd;

	path = ft_split(ft_find_path(env, "PATH"), ':');
	if (!path)
		ft_malloc_error(2, NULL, path);
	command_lst = make_list(path, ac, av, 2);
	ft_parcer(ac, av, &command_lst, 2);
	fd.out = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	fd.in = open(av[1], O_RDWR);
	pipex((command_lst), env, &fd);
	ft_free_list(&command_lst);
}

int	main(int ac, char *av[], char *env[])
{
	int			x;

	x = 0;
	if (!env[0])
		return (0);
	if (ac < 5)
	{
		write (1, "argc error\n", 10);
		exit(0);
	}
	else
	{
		if (ac == 6 && ft_strcmp(av[1], "here_doc") == 0)
		{
			here_doc_pipe(env, av, ac);
		}
		else
		{
			multiple_pipe(env, av, ac);
		}
	}
	return (0);
}
