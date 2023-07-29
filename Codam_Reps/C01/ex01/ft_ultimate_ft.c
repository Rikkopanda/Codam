/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:05 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/18 12:02:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}
//0x48 receives val 0x42
// does pointer 8 times and starts at value of nbr
//int* nbr points to address of int type, *nbr points to value of address nbr
/*
int	main(void)
{
	int a;	//0x0 val empty
	int *pi1; // 0x4 val empty
	int **pi2; // 0x8 val empty
	int ***pi3;
	int ****pi4; 
	int *****pi5; 
	int ******pi6; 
	int *******pi7; 
	int ********pi8; // 0x42 holds val empty

	a = 66; // 0x4 has now val 66
	pi1 = &a; // 0x4 has now val 0x0
	pi2 = &pi1;// 0x8 has now val 0x4
	pi3 = &pi2;
	pi4 = &pi3;
	pi5 = &pi4;
	pi6 = &pi5;
	pi7 = &pi6;	
	pi8 = &pi7; // 0x42 has now val 0x36

	ft_ft(&pi8);
}
//send the address of a as parameter to function
*/