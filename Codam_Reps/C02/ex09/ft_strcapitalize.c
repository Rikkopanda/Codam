/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:08 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/25 18:42:36 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	if_alpha_return_0(char letter)
{
	if ((letter >= 'a' && letter <= 'z') || 
		(letter >= 'A' && letter <= 'Z') || 
		(letter >= '0' && letter <= '9'))
	{
		return (0);
	}
	return (1);
}

void	make_str_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	make_str_lowercase(str);
	i = 0;
	while (str[i] != '\0' && !(str == '\0'))
	{
		if (str[0] >= 'a' && str[0] <= 'z')
			str[0] = str[0] - 32;
		if (if_alpha_return_0(str[i]))
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
				str[i + 1] = str[i + 1] - 32;
		}
		i++;
	}
	return (str);
}
//when a space index is known, 
//make character right after 
//it uppercase when possible. 
//also very first of array
// int main(void)
// {
// char a[] = "als je van, 42bEren -leren kan";;

// printf("%s",ft_strcapitalize(a));
// }
