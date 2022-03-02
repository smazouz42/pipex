/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:10:05 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/27 19:03:24 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free_tab(char **tab)
{
	int	len;

	if (!*tab)
		return ;
	len = 0;
	while (tab[len])
	{
		free(tab[len]);
		len++;
	}
	free(tab);
}

void	ft_free_list(t_list **lst)
{
	t_list	*head;
	t_list	*tmp;

	if (!*lst)
		return ;
	head = (*lst);
	if (head->path)
		ft_free_tab(head->path);
	while (head)
	{
		if (head->command_path)
			ft_free_tab(head->command_path);
		if (head->n_cmd)
			free(head->n_cmd);
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*lst = NULL;
}
