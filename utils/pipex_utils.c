/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:32:29 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/27 19:03:24 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pipex.h"

char	*ft_command(char *str)
{
	int		len;
	char	*command;

	len = 0;
	while (str[len] != ' ' && str[len])
		len++;
	command = malloc((len + 1));
	if (!command)
		return (NULL);
	len = 0;
	while (str[len] != ' ' && str[len])
	{
		command[len] = str[len];
		len++;
	}
	command[len] = '\0';
	return (command);
}

int	ft_permissions(t_list *cmd)
{
	int		len;
	char	*command;

	len = 0;
	if (cmd->n_cmd[0] == '\0')
	{
		ft_putstr("access : command not found\n");
		exit(1);
	}
	cmd->command_path = ft_paths(cmd->path, cmd->n_cmd);
	while (cmd->command_path[len])
	{
		command = ft_command(cmd->command_path[len]);
		if (access(command, F_OK) == 0 && access(command, X_OK) == 0)
		{
			free(command);
			return (0);
		}
		free(command);
		len++;
	}
	return (-1);
}

void	ft_check_commands_permission(t_list **command_lst)
{
	t_list	*head;

	head = (*command_lst);
	while (head)
	{
		if (ft_permissions(head) == -1 && (access(head->n_cmd, F_OK) == -1
				|| access(head->n_cmd, R_OK) == -1))
		{
			ft_free_list(command_lst);
			perror(head->n_cmd);
			exit(0);
		}
		head = head->next;
	}
}

void	ft_parcer(int size, char **array, t_list **command_lst)
{
	int	fd;

	if (!*array)
		return ;
	fd = open(array[size - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	close(fd);
	if (access(array[1], F_OK) == -1 || access(array[1], R_OK) == -1)
	{
		ft_free_list(command_lst);
		perror(array[1]);
		exit(0);
	}
	if (access(array[size - 1], F_OK) == -1
		|| access(array[size - 1], W_OK) == -1)
	{
		ft_free_list(command_lst);
		perror(array[size - 1]);
		exit(0);
	}
	ft_check_commands_permission(command_lst);
}

t_list	*make_list(char **path, int size, char *av[])
{
	int		x;
	t_list	*command_lst;

	x = 2;
	size = size - 3;
	command_lst = ft_lstnew(path, av[x], ft_command(av[x]));
	if (!command_lst)
		ft_malloc_error(1, &command_lst, NULL);
	x++;
	size--;
	while (size > 0)
	{
		ft_lstadd_back(&command_lst, ft_lstnew(path, av[x], ft_command(av[x])));
		x++;
		size--;
	}
	return (command_lst);
}
