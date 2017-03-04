/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:17:00 by sleung            #+#    #+#             */
/*   Updated: 2017/03/03 16:16:16 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static void	init_data(t_struct *d)
{
	d->null = 0;
	d->conv = 0;
	d->flag = 0;
	d->sharp = 0;
	d->zero = 0;
	d->minus = 0;
	d->plus = 0;
	d->space = 0;
	d->mw = 0;
	d->p = 0;
	d->lm = 0;
}

static int	fill_data(va_list ap, t_struct *d, t_format *f)
{
	int	len;

	len = 0;
	check_flags(d, f, ap);
	if (check_conv(d, f) == 1)
		len = read_data(ap, d, f);
	else if (d->mw)
		len = ft_printf_c(f->fo[f->i++], d);
	return (len);
}

static int	char_out(t_format *f)
{
	write(1, &(f->fo[f->i]), 1);
	f->i++;
	return (1);
}

static void	erase_data(t_struct **tmp)
{
	t_struct *d;

	d = *tmp;
	d->conv = 0;
	d->flag = 0;
	d->zero = 0;
	d->minus = 0;
	d->plus = 0;
	d->space = 0;
	d->mw = 0;
	d->p = 0;
	d->lm = 0;
	free(d);
	d = NULL;
}

int			ft_printf(const char *format, ...)
{
	int				len;
	t_format		*f;
	t_struct		*d;
	va_list			ap;

	len = 0;
	if (!(f = (t_format *)malloc(sizeof(t_format))))
		return (-1);
	f->i = 0;
	f->fo = (char *)format;
	va_start(ap, format);
	while (f->fo[f->i] != '\0')
	{
		if (f->fo[f->i] == '%')
		{
			if (!f->fo[++f->i])
				break ;
			if (!(d = (t_struct *)malloc(sizeof(t_struct))))
				return (-1);
			init_data(d);
			len += fill_data(ap, d, f);
			erase_data(&d);
		}
		else
			len += char_out(f);
	}
	va_end(ap);
	if (f)
		free(f);
	return (len);
}
