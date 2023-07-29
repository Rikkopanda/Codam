/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:05 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/14 11:43:33 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a / *b;
	*b = *a % *b;
	*a = c;
}
/*
int	main(void)
{
	int bb;
	int aa;
	bb = 13;
	aa = 50;
	ft_ultimate_div_mod(&aa, &bb);
}*/
