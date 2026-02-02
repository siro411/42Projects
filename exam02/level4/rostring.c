#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	flag;
	int	start;
	int	end;

	if (argc > 1)
	{
		i = 0;
		flag = 0;
		end = 0;
		while (argv[1][i] && (argv[1][i] == '\t' || argv[1][i] == ' '))
			i++;
		start = i;
		while (argv[1][i])
		{
			if (flag)
			{
				while (argv[1][i] && argv[1][i] != '\t' && argv[1][i] != ' ')
				{
					write(1, &argv[1][i], 1);
					i++;
				}
				write(1, " ", 1);
			}
			else
			{
				while (argv[1][i] && argv[1][i] != '\t' && argv[1][i] != ' ')
				{
					i++;
				}
				end = i;
			}
			while (argv[1][i] == '\t' || argv[1][i] == ' ')
			{
				i++;
			}
			flag = 1;
		}
		while (start < end)
		{
			write(1, &argv[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
