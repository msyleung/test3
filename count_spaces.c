/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:51:55 by sleung            #+#    #+#             */
/*   Updated: 2017/02/23 13:57:14 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_zeros(t_struct *d, int len, int n)
{
	if (d->p == -1)
		return (d->mw);
	else if (d->p != 0 && d->p > len && n > 0)
		return (d->p - len);
	else if (d->p != 0 && d->p > len && n < 0)
		return ((d->p + 1) - len);
	else if (d->p != 0 && d->mw > d->p && d->p < len)
		return (d->mw - d->p);
	else if (d->p != 0 && d->mw > d->p && d->p > len)
		return (d->p - len);
	return (0);
}

int	count_spaces_int(t_struct *d, int len, int n)
{
	if (d->p == -1)
		return (d->mw);
	else if (d->mw > d->p && d->p > len && n < 0)
		return ((d->mw - 1) - d->p);
	else if (d->mw > d->p && d->p > len)
		return (d->mw - d->p);
	else if (d->mw < d->p)
		return (0);
	return (d->mw - len);
}

int	count_spaces(t_struct *d, int len)
{
	if (d->p == -1)
		return (d->mw);
	else if (d->p == 0 && d->mw > 0 && len > 0 && d->mw > len)
		return (d->mw - len);
	else if (d->p == 0 && d->mw > 0 && len == 0)
		return (d->mw);
	else if (d->p != 0 && d->mw > d->p && d->p < len)
		return (d->mw - d->p);
	else if (d->p != 0 && d->mw > d->p && d->p > len)
		return (d->mw - len);
	else if (d->p != 0 && d->mw < d->p && d->mw > len)
		return (d->mw - len);
	return (0);
}

int	write_zeros(int zeros, char *tmp, int ti)
{
	while (zeros > 0)
	{
		tmp[ti++] = '0';
		zeros--;
	}
	return (ti);
}

int	write_spaces(int spaces, char *tmp, int ti)
{
	while (spaces > 0)
	{
		tmp[ti] = ' ';
		ti++;
		spaces--;
	}
	return (ti);
}
