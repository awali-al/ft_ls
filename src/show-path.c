#include "../includes/ft_ls"

void	show_dir(char *path, ust o)
{
	DIR *di;
	struct dirent sb;

	di =opendir(".");

	if(dir == NULL )
	{
		ft_printf("no such file in directory");
		exit(1);
	}	
	while(sb=readdir(di) != NULL)
	{
			
	}
}