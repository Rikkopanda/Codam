/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:41:22 by rverhoev          #+#    #+#             */
/*   Updated: 2023/08/02 23:16:23 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// int		ft_strlen(char *str);
// void	joinloops(char *strs, char *sep, char	**totalstring, int	*last);

void	joinloops(char *strs, char *sep, char	**totalstring, int	*last)
{
	int	j;

	j = 0;
	while (strs[j] != '\0')
	{
		(*totalstring)[*last + j] = strs[j];
		j++;
	}
	*last += j;
	j = 0;
	while (sep[j] != '\0')
	{
		(*totalstring)[*last + j] = sep[j];
		j++;
	}
	*last += j;
	return ;
}

/*ft_strlen(strs[i])
i		0	1				1					1
j		0	1	2	3	0	1	2	3	0	1	2	3	0
last	0	1	2	3	4	5	6	7	8	9	10	11	12
		t	r	e	e		m	h		b	o	w	l
"tree","bowl","hats","mice","toon"
*/
// int main(void)
// {
// 	int size;
// 	char *strarr[5]={
// 	"tree","bowl","hats","mice","toon"};
// 	char seperator[] = " hm ";
// 	char *totalstring = ft_strjoin(1, strarr, seperator);
// 	printf("\n%s\t lenght = %d", totalstring, ft_strlen(totalstring));
// }

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
