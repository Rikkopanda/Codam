/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rik <rik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:34:57 by rverhoev          #+#    #+#             */
/*   Updated: 2024/01/05 13:30:06 by rik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// argv[1],argv[2],argv[3],argv[4], NULL	argc = 5
// < file | cmd1 | cmd2 > file2
// zelfde als(als shell command):
// < file cmd1 | cmd2 > file2 (vanwege <)

void	close_pipes(int *pipe, int increment)
{
	int	i;

	i = 0;
	while (i <= increment)
	{
		close(pipe[WRITE]);
		close(pipe[READ]);
		pipe = pipe - 1;
		i++;
	}
}

void	closing_parent_pipes_if(int *i, int *pipe_i, t_data *data)
{
	if (*pipe_i == 2)
		close((*data).pipe_array[*pipe_i - 1][READ]);
	else if (*pipe_i > 2 && *i != (*data).nbr_of_cmds)
		close_pipes((*data).pipe_array[*pipe_i - 1], 0);
	errno = 0;
}

int	pipe_loop(int *i, int *pipe_i, t_data *data)
{
	int		status;
	pid_t	p;

	while (1)
	{
		p = fork();
		if (p == -1)
			return (close_pipes((*data).pipe_array[*pipe_i], 1), wait(&status), -1);
		else
			(*data).nbr_of_forks++;
		if (p != 0)
			closing_parent_pipes_if(i, pipe_i, data);
		if (p == 0)
			cmd((*data).pipe_array[*pipe_i - 1], (*data).pipe_array[*pipe_i], *i, data);
		if (*i == 1 || (*i == 2 && (*data).heredoc_bool))
			write_from_parent_to_cmd((*data).pipe_array[*pipe_i - 1], (*data).pipe_array[*pipe_i],
				(*data).buf, data);
		if (*i == (*data).nbr_of_cmds)
			break ;
		(*i)++;
		(*pipe_i)++;
		if (pipe((*data).pipe_array[*pipe_i]) == -1)
			return (wait(&status), close_pipes((*data).pipe_array[*pipe_i - 1], 1), -1);
	}
	return (0);
}

void	free_pipe_array(t_data *data, int j)
{
	while (j >= 0)
	{
		free((*data).pipe_array[j]);
		(*data).pipe_array[j] = 0;
		j--;
	}
	free((*data).pipe_array);
	(*data).pipe_array = 0;
}

int	alloc_pipe_array(t_data *data)
{
	int	j;

	j = 0;
	(*data).pipe_array = malloc(sizeof(int *) * ((*data).nbr_of_cmds + 2));
	if (!(*data).pipe_array)
		return (-1);
	while (j < (*data).nbr_of_cmds + 2)
	{
		(*data).pipe_array[j] = (int *)malloc(sizeof(int) * 2);
		if (!(*data).pipe_array[j])
			return (free_pipe_array(data, j), -1);
		j++;
	}
	return (0);
}

int	start_piping(t_data *data)
{
	int		i;
	int		pipe_i;

	alloc_pipe_array(data);
	if (pipe((*data).pipe_array[0]) == -1)
		return (-1);
	if (pipe((*data).pipe_array[1]) == -1)
		return (close_pipes((*data).pipe_array[1], 0), -1);
	pipe_i = 1;
	if ((*data).heredoc_bool)
		i = 2;
	else
		i = 1;
	if (pipe_loop(&i, &pipe_i, data) == -1)
		return (-1);
	receive((*data).pipe_array[pipe_i - 1], (*data).pipe_array[pipe_i], data, &i);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 4)
		return (0);
	set_data(argc - 3, envp, &data);
	if (parse_args(&data.args, argv, argc, &data) == -1)
		return (free_args(&data.args), 1);
	if (data.heredoc_bool && argc < 5)
		return (free_args(&data.args), 1);
	data.buf = read_file(argv[1], -1, &data, &data.args);
	if (start_piping(&data) == -1)
		return (free_args(&data.args), free(data.buf), 1);
	write_out_pluscleanup(&data, data.buf, argc - 1 - 1);
	return (WEXITSTATUS(data.status));
}
	//printf("%d\n", 	errno);
	//printf("%d", WEXITSTATUS(errno));