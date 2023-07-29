/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_next_prime.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:45:20 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/26 08:14:43 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int is_prime(int num)
{	
	int i;

	i = 2;
	if(num < 2)
		return (0);

	while(i <= num / 2)
	{
		if(num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_next_prime(int nb)
{
	if(nb == 0 || nb == 1)
		nb = 2;
	
	while(nb < 2147483646)
	{
		if (is_prime(nb))
			return(nb);
		nb++;
	}
	return(0);
}
//als nb/2 deelbaar is door een getal 2 of groter, dan is het geen priem
//nb = 4. 4/2 = 2. 2 % 2 = 0
int	main(void)
{
      printf("%d ",ft_is_next_prime(4));            
}