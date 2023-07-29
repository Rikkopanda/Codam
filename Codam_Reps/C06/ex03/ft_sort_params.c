/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:17:55 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/28 10:33:29 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *argv1, char *argv2);

int	print(int argc, char **argv);

int	main(int argc, char **argv)
{
	int		i;
	char	*temp;	
	int		len;

	len = argc - 1;
	i = 1;
	while (1 < len)
	{
		while (i < len)
		{
			if (ft_strcmp(argv[i], argv[len]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[len];
				argv[len] = temp;
			}
			i++;
		}
		i = 1;
		len--;
	}
	print (argc - 2, &argv[1]);
	return (0);
}
//argv ontvangen
//argvs vergelijken
//argv[1 a 2 a 3] pointer is eerste adress van array
//vanaf argv[1] vergelijk tot + (argc - 1)
//print((argc - 2), &argv[1]);//argc - omdat index en start 1 later
//print(argc - 2, &argv[1]);

int	ft_strcmp(char *argv1, char *argv2)
{
	int	i;

	i = 0;
	while (argv1[i] != '\0' || argv2[i] != '\0')
	{
		if (argv1[i] != argv2[i])
			return ((unsigned char)argv1[i] - (unsigned char)argv2[i]);
		i++;
	}
	return (0);
}

int	print(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= argc)
	{
		while (argv[j][i] != '\0')
		{
			write(1, &argv[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		i = 0;
		j++;
	}
	return (0);
}
