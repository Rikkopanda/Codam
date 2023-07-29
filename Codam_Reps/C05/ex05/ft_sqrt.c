/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:45:20 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/24 16:28:37 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int i;

	i = 1;
	if(nb <= 0)
		return (0);
	while((i * i) < nb)
		i++;
	if((i * i) > nb)
		i--;
	return(i);
}

int	main(void)
{
      printf("%d ",ft_sqrt(23));            
}	