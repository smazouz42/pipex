/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:51:36 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/27 19:04:30 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pipex_bonus.h"

t_list	*ft_lstnew(char **path, char *command, char *new_cammand)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->path = path;
	list->cmd = command;
	list->n_cmd = new_cammand;
	list->next = NULL;
	return (list);
}
