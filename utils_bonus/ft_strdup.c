/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:27:03 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/20 14:47:28 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pipex_bonus.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	s;
	unsigned int	i;
	char			*dst;

	i = 0;
	s = 0;
	while (s1[s] != '\0')
		s++;
	dst = (char *)malloc((s + 1) * sizeof(*dst));
	if (dst == 0)
		return (NULL);
	while (i < s)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
