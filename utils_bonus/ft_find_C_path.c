/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_C_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:51:09 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/27 18:24:09 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pipex_bonus.h"

int	check_name(char *str, int *l, const char *path)
{
	int		x;

	x = 0;
	while (str[x])
	{
		if (str[x] != path[x])
			break ;
		x++;
	}
	if (x == ft_strlen(path))
	{
		*l = x;
		return (1);
	}
	else
		return (0);
}

char	*ft_find_path(char **env, const char *path)
{
	int	x;
	int	*l;
	int	y;

	y = 0;
	x = 0;
	l = &y;
	while (env[x])
	{
		if (check_name(env[x], l, path) == 1 && env[x][*l] == '=')
			return (env[x] + (*l + 1));
		x++;
	}
	return (NULL);
}

char	*ft_optimize_path(char *path, char *command)
{
	int		size;
	char	*new_path;
	int		x;
	int		y;

	x = -1;
	y = 0;
	size = strlen(path) + strlen(command) + 2;
	new_path = malloc(size);
	if (!new_path)
		return (NULL);
	while (path[++x])
		new_path[x] = path[x];
	new_path[x] = '/';
	x++;
	while (command[y])
	{
		new_path[x] = command[y];
		x++;
		y++;
	}
	new_path[x] = '\0';
	return (new_path);
}

int	ft_size_count(char **path)
{
	int	size;

	size = 0;
	while (path[size])
		size++;
	return (size);
}

char	**ft_paths(char **path, char *command)
{
	int		x;
	int		array_size;
	char	**new_path;

	array_size = ft_size_count(path);
	new_path = (char **)malloc((array_size + 1) * sizeof(char *));
	if (!new_path)
		return (NULL);
	x = 0;
	while (path[x])
	{
		new_path[x] = ft_optimize_path(path[x], command);
		x++;
	}
	new_path[x] = NULL;
	return (new_path);
}
