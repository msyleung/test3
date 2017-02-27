/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:05:39 by sleung            #+#    #+#             */
/*   Updated: 2017/02/27 15:12:53 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrdel(char **as, int ti)
{
	char	*tmp;
	int		n;

	n = -1;
	if (!as)
		return (0);
	if (*as != NULL)
	{
		tmp = *as;
		while (++n < ti)
			write(1, tmp++, 1);
		free(*as);
		*as = NULL;
	}
	return (n);
}
