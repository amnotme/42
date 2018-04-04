#include <stdio.h>

int main(int ac, char **av, char **env)
{
	int i = 1;
	while (i < ac)
	{
		printf("index = %d, argument = %s\n", i, av[i]);
		i++;
	}

	i = 0;
	while (env[i])
	{
		printf("environment variable # %d, value = %s\n", i, env[i]);
		i++;
	}

	return (0);
}
