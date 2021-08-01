#include "pipex.h"
/* TODO правильный возврат ошибки после execve
 * название файла ``...'' такой же как ввод комманды
 */

void	initialize_data(int argc, char *argv[], char *envp[], t_data *data)
{
	data->ind = argc - 1;
	data->cntCmnds = argc - 3 / 2;
	data->cmnds = malloc(sizeof(*data->cmnds) * (data->cntCmnds + 1));
	if (data->cmnds == NULL)
		error_exit("Malloc error\n", 2);
	data->cmnds[data->cntCmnds] = NULL;
	data->infile = argv[1];
	data->outfile = argv[data->ind];
	data->argv = argv;
	data->envp = envp;
}

void	validation_of_args(int argc, char *argv[])
{
	if (argc != 7)
		error_exit("Wrong usage\n", 1);
	if (access(argv[1], F_OK) == -1)
		errno_exit(argv[1]);
}

void	parse_commands(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < data->cntCmnds)
	{
		data->cmnds[i] = malloc(sizeof(**data->cmnds) * 2);
		data->cmnds[i][0] = data->argv[j + 2];
		data->cmnds[i][1] = data->argv[j + 3];
		j += 2;
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	int i = 0;

	validation_of_args(argc, argv);
	initialize_data(argc, argv, envp, &data);
	parse_commands(&data);
	i = 0;
	while(i < 2)
	{
		printf("%s %s\n", data.cmnds[i][0], data.cmnds[i][1]);
		i++;
	}

    return 0;
}
