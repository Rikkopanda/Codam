/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:45:20 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/24 16:07:07 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	int array[12];
	int totaal;
	// array[0] = 0;
	// array[1] = 1;
	// array[2] = 1;
	if(index < 0)
		return(-1);
	if(index == 0)
		return(0);
	if(index == 1)
		return(1);
	else
		return(ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

int	main(void)
{
	int i;
	int n = 22;
	// for(i = 0;i<n;i++) {
      printf("%d ",ft_fibonacci(10));            
 //  }
}