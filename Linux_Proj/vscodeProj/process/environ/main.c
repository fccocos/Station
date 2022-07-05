#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

extern char **environ;

int main(int argc, char *argv[])
{

	if(argc==2)//清空环境变量
	{
		if(!strcasecmp(argv[1],"--clear"))
		{
			if(clearenv()==-1)
			{
				fprintf(stderr,"Clearing the eviron list unsuccessfully.\n");
				exit(EXIT_FAILURE);
			}
			fprintf(stdout,"stdout: Clearing the eviron list successfully\n");
		}
	}
	else if (argc == 3) //添加环境变量
	{
		if (!strcasecmp(argv[2], "--del"))
		{
			if (getenv(argv[1])==NULL)
			{
				//需要删除的环境变量不在环境列表中
				fprintf(stderr, "the env is no exsited in the environ list\n");
				exit(EXIT_FAILURE);
			}
			unsetenv(argv[1]); //删除环境变量
		}
		else
		{

			int ret;
			ret = setenv(argv[1], argv[2], 0); //删除环境变量或果添加的环境已经存在，则什么都不做
			if (ret == -1)
			{
				fprintf(stderr, "Adding \"%s=%s\" unsuccessfully.\n", argv[1], argv[2]);
				exit(EXIT_FAILURE);
			}
		}
	}
	else if (argc == 4) //修改已经存在的环境变量
	{
		if (!strcasecmp(argv[3], "--modify"))
		{
			fprintf(stderr,"stdout: Enter into modification mode\n");
			if (getenv(argv[1])!=NULL)
			{
				//环境变量已经存在
				//修改环境变量
				int ret = setenv(argv[1], argv[2], 1);
				if (ret == -1)
				{
					fprintf(stderr, "Modifying \"%s\" unsuccessfully.\n", argv[1]);
				}
			}
			else
			{
				fprintf(stderr, "%s is no exist in the environ list\n", argv[1]);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "%s/t no argument, or invaild argument\n", argv[0]);
		fprintf(stderr, "Uerage:\n\t%s [name|--clear]  [value|--del] [--modify]\n", argv[0]);
		fprintf(stderr, "Tips:\n\t 1.When you delete an env to envron list, you must use the option \"--del\"\n");

		fprintf(stderr, "\t 2.When you modify an env, you must use the option \"--modify\"\n");
		fprintf(stderr, "\t 3.When you add an env, you can't use 3rd option\n");
	}
	//显示环境变量列表
	char **ep = NULL;
	if (environ != NULL)
		for (ep = environ; *ep != NULL; ep++)
			fprintf(stdout, "%s\n", *ep);
	exit(EXIT_SUCCESS);
}
