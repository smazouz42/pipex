/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:27:18 by smazouz           #+#    #+#             */
/*   Updated: 2022/03/02 11:56:43 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	*rest_of_line(char *line)
{
	int		len;
	int		len_;
	char	*rest;

	len = 0;
	len_ = 0;
	rest = malloc(ft_get_line(line) + 2);
	if (!rest)
		return (NULL);
	len = 0;
	while (line[len] != '$' && line[len] != '\0')
	{
		rest[len] = line[len];
		len++;
	}
	len_ = len + 1;
	while (is_alpha_n(line[len_]) == 0 && line[len_])
		len_++;
	while (line[len_])
		rest[len++] = line[len_++];
	rest[len] = '\n';
	rest[len + 1] = '\0';
	return (free(line), rest);
}

char	*ft_make_new_line(char *line, char *var, int size, int dollar_number)
{
	int		var_len;
	int		var_len_;
	int		new_var;
	char	*new_line;
	char	*v_name;

	v_name = var_name(line);
	new_var = -1;
	var_len = -1;
	var_len_ = 0;
	new_line = malloc(size + 2);
	if (!new_line)
		return (NULL);
	while (line[++var_len])
	{
		if (line[var_len_] == '$' && dollar_number == 0)
		{
			dollar_number++;
			while (var[++new_var])
				new_line[var_len_++] = var[new_var];
			var_len += (ft_strlen(v_name) + 1);
		}
		new_line[var_len_++] = line[var_len];
	}
	return (free(line), free(v_name), new_line[var_len_ - 1] = '\n', new_line[var_len_] = '\0', new_line);
}

char	*up_line(char *line, char **env)
{
	char	*var;
	int		size;
	int		dollar_number;
	char	*v_name;

	dollar_number = 0;
	v_name = var_name(line);
	var = ft_find_path(env, v_name);
	if (!var)
		return (free(v_name), rest_of_line(line));
	size = (ft_strlen(line) + ft_strlen(var)) - ft_strlen(v_name);
	free(v_name);
	return (ft_make_new_line(line, var, size, dollar_number));
}

int	check_for_dollar(char *line)
{
	int	len;

	if (!line)
		return (0);
	len = 0;
	while (line[len])
	{
		if (line[len] == '$')
			return (-1);
		len++;
	}
	return (len);
}

void	read_from_here_doc(t_list **lst, int fd_in, char *limiter, char **env)
{
	char	*line;

	line = ft_read();
	if (!line)
		exit(1);
	while (ft_strcmp(line, limiter) != 10)
	{
		if (ft_strlen(line) == 0)
		{
			free(line);
			return ;
		}
		while (check_for_dollar(line) == -1)
		{
			line = up_line(line, env);
			if (!line)
				ft_malloc_error(1, lst, NULL);
		}
		ft_putstr_fd(line, fd_in);
		free(line);
		line = ft_read();
	}
	free(line);
}
