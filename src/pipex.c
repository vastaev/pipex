#include "pipex.h"
/* TODO правильный возврат ошибки после execve
 * название файла ``...'' такой же как ввод комманды
 */
void initialize_data(int argc, char *argv[], char *envp[], t_data *data)
{
	data->cmnds = malloc(sizeof(*data->cmnds) * (argc - 2));
	data->cntCmnds = argc - 3;
	data->cmnds[data->cntCmnds] = NULL;
	data->infile = argv[1];
	data->outfile = argv[argc - 1];
	data->argv = argv;
	data->envp = envp;

}

int	is_command(char *str)
{
	int	strLen;

	strLen = (int)ft_strlen(str);
	if (str[0] == '`' && str[1] == '`')
		return (1);
	else if (str[strLen - 1] == '\'' || str[strLen - 2] == '\'')
		return (2);
	else
		return (0);
}

int	count_commands(int argc, char *argv[])
{
	int	i;
	int	cmdsCounter;

	cmdsCounter = 0;
	i = 2;
	while(i < argc - 1)
	{
		if (is_command(argv[i]) == 1)
			cmdsCounter++;
		i++;
	}
	return (cmdsCounter);
}

void	validation_of_args(int argc, char *argv[])
{
	if (is_command(argv[1]) || is_command(argv[argc - 1]))
		error_exit("Change file name\n", 1);
	if (count_commands(argc, argv) != 2)
		error_exit("Wrong usage\n", 1);
}


//t_data	parse_commands(t_data data)
//{
//	int	i;
//
//	i = 0;
//	while (!ft_isalpha(data.argv[2][i]))
//		i++;
//	data.cmnds[0][0] = ft_substr(data.argv[2], i, ft_strlen());// command
//	// Если следующий аргумент начинается с дефиса, то у команды есть флаги
//	if (data)
//	data.cmnds[1] = data.argv[3];
//	return (data);
//}

int main(int argc, char *argv[], char *envp[])
{
    int fd[2];
    int pid1;
    int	pid2;
    t_data	data;

    validation_of_args(argc, argv);
//    initialize_data(argc, argv, envp, &data);
//	parse_commands(data);
//	if (pipe(fd) == -1)
//		return (2);
//    pid1 = fork();
//    if (pid1 == -1)
//		return (1);
//	if (pipe(fd) == -1)
//		return (2);
//    if (pid1 == 0)
//	{
//		close(fd[0]);
//		execve(argv[1], );
//	}
    return 0;
}
