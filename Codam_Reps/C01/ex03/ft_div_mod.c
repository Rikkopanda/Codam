/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:05 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/16 10:48:10 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int be;
	int aa;
	int div;
	int rem;

	be = 13;
	aa = 50;
	ft_div_mod(aa, be, &div, &rem);
}//50:13 krijg je 3 apples per persoon een er zijn 11 appels(hele ints over)
*/