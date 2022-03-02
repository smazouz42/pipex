/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:52:11 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/27 19:09:48 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pipex.h"

void	ft_malloc_error(int n, t_list **lst, char **path)
{
	if (n == 2)
		ft_free_tab(path);
	else if (n == 1)
		ft_free_list(lst);
	ft_putstr("malloc :There Is Not Enough Space For Allocation\n");
	exit(1);
}

void	arc_error(void)
{
	write (1, "error in argc\n", 13);
	exit(1);
}
