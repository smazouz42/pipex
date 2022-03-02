/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:19:06 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/27 19:04:30 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pipex_bonus.h"

static char	*path(char *new_command, char **path)
{
	int		x;
	char	**new_path;

	if (access(new_command, F_OK) == 0 && access(new_command, X_OK) == 0)
		return (new_command);
	new_path = ft_paths(path, new_command);
	x = 0;
	while (new_path[x])
	{
		if (access(ft_command(new_path[x]), F_OK) == 0
			&& access(ft_command(new_path[x]), X_OK) == 0)
			return (new_path[x]);
		x++;
	}
	return (NULL);
}

void	loop_pipe(char **env, t_list *cmd, int *p, t_struct *list)
{
	dup2(list->in, 0);
	if (cmd->next)
		dup2(p[1], 1);
	if (!cmd->next)
		dup2(list->out, 1);
	close(p[0]);
	if (execve(path(cmd->n_cmd, cmd->path), ft_split(cmd->cmd, ' '), env) == -1)
	{
		ft_free_list(&cmd);
		perror("exeve :");
		exit(0);
	}
}

void	pipex(t_list *cmd, char **env, t_struct *list)
{
	int	p[2];
	int	pid;

	while (cmd)
	{
		pipe(p);
		pid = fork();
		if (pid == -1)
			exit(1);
		else if (pid == 0)
			loop_pipe(env, cmd, p, list);
		else
		{
			close(p[1]);
			list->in = p[0];
			cmd = cmd->next;
		}
	}
	while (1)
	{
		if (waitpid(0, 0, 0) == -1)
			break ;
	}
	unlink("temp");
}
