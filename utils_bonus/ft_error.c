/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:32:57 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/27 17:51:25 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pipex_bonus.h"

void	ft_malloc_error(int n, t_list **lst, char **path)
{
	if (n == 2)
		ft_free_tab(path);
	else if (n == 1)
		ft_free_list(lst);
	ft_putstr("malloc :There Is Not Enough Space For Allocation\n");
	exit(1);
}
