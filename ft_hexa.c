/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 03:02:07 by paboutel          #+#    #+#             */
/*   Updated: 2020/02/26 18:49:14 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_put_esphexa(unsigned long int nb, int *tab, char c)
{
	int		i;

	i = ft_hexlen(nb, tab);
	tab[4] = tab[4] - i;
	if (tab[0] == 0)
	{
		ft_puthexa(' ', tab[4], tab);
		ft_hexa(nb, c, tab);
	}
	if (tab[0] == 1)
	{
		ft_hexa(nb, c, tab);
		ft_puthexa(' ', tab[4], tab);
	}
}

int		ft_put_0hexa(unsigned long int nb, int n, char c, int *tab)
{
	int		i;

	i = ft_hexlen(nb, tab);
	if (nb == 0 && n == 0)
		return (0);
	if (nb < 0)
	{
		write(1, "-", 1);
		tab[7]++;
		nb = -nb;
	}
	n = n - i;
	ft_puthexa('0', n, tab);
	ft_hexa(nb, c, tab);
	return (0);
}

int		ft_preci2hexa(unsigned long int nb, int *tab, char c)
{
	if (tab[5] > 0)
		tab[4] = tab[4] - tab[5];
	if (nb == 0 && tab[5] == 0)
	{
		ft_puthexa(' ', tab[4], tab);
		return (0);
	}
	if (tab[0] == 0 && tab[1] == 0)
		ft_puthexa(' ', tab[4], tab);
	if (tab[1] == 1 && tab[5] < 0)
		ft_puthexa('0', tab[4], tab);
	ft_puthexa('0', tab[5], tab);
	ft_hexa(nb, c, tab);
	if (tab[0] == 1)
		ft_puthexa(' ', tab[4], tab);
	return (0);
}

int		ft_precihexa(unsigned long int nb, int *tab, char c)
{
	int	i;

	i = ft_hexlen(nb, tab);
	tab[4] = tab[4] - i;
	tab[5] = tab[5] - i;
	if (tab[4] <= tab[5])
	{
		ft_puthexa('0', tab[5], tab);
		ft_hexa(nb, c, tab);
	}
	else
		ft_preci2hexa(nb, tab, c);
	return (0);
}

void	ft_printhexa(int tab[8], unsigned int nb, char c)
{
	if (tab[5] < 0)
		tab[3] = 0;
	if (tab[3] == 1)
		tab[1] = 0;
	if (tab[4] == 0 && nb == 0 && tab[3] == 0)
		tab[4]++;
	if (tab[2] == 0)
	{
		if (tab[3] == 0)
			ft_hexa(nb, c, tab);
		else
			ft_put_0hexa(nb, tab[5], c, tab);
	}
	else
	{
		if (tab[3] == 0 && tab[1] == 0)
			ft_put_esphexa(nb, tab, c);
		if (tab[3] == 0 && tab[1] == 1)
			ft_put_0hexa(nb, tab[4], c, tab);
		if (tab[3] == 1)
			ft_precihexa(nb, tab, c);
	}
}
