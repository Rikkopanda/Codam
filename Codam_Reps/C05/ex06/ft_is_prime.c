/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:45:20 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/26 18:19:51 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	if(nb < 2)
		return (0);

	while(i <= (nb / 2))
	{
		if(nb % i  == 0)
			return (0);
		i++;
	}
	return(1);
}
//als nb/2 deelbaar is door een getal 2 of groter, dan is het geen priem
//nb = 4. 4/2 = 2. 2 % 2 = 0
int	main(void)
{
	printf("%d ",ft_is_prime(5));            
}