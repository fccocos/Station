/**
 * @file getopt.c
 * @author gunfire (gunfirefc70@163.com)
 * @brief 测试getopt函数
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void
usageError(const char *progName, char *msg, int opt);

int main(int argc, char *argv[])
{
    char *pstr = NULL; //用于指向有参选项的参数
    int opt;           //用于返回getopt函数的返回结果
    while ((opt = getopt(argc, argv, ":a:b:cde")) != -1)
    {
        printf("opt = %3d (%c); optind = %d; optarg = %s\n",
               opt,
               (unsigned char)opt,
               optind,
               optarg);
        if (opt == '?' || opt == ':')
            printf("optopt = %3d (%c); optind = %d\n",
                   optopt,
                   (unsigned char)optopt,
                   optind);
        switch (opt)
        {
        case 'a':
            //在对应的选项开管中调用相应的函数
            printf("there is the option a, who is a option with argument:%s\n", optarg);
            break;
        case 'b':
            printf("there is the option b, who is a option with argument:%s\n", optarg);
            break;

        case 'c':
            printf("there is the option c, who is a option without argument\n");
            break;
        case 'd':
            printf("there is the option d, who is a option without argument\n");
            break;
        case ':':
            usageError(argv[0], "Missing argument", optopt);
        case '?':
            usageError(argv[0], "Unrecognized option", optopt);
        default:
            fprintf(stderr, "Unexpected case in switch()\n");
            break;
        }
    }

    if(opt==-1&&argc==1&&optind==1)
    {
        fprintf(stderr, "there is not any option or argument in your command line, please input some arguments\n");
        fprintf(stderr, "\t Usage:%s [-a arg1] [-b arg2] [-c] [-d] arg3\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if(optind<argc)
    {
        fprintf(stdout,"there is a non-option argument:%s in command line, or, just one\n", argv[optind]);
        exit(EXIT_SUCCESS);
    }


    exit(EXIT_SUCCESS);
}

static void
usageError(const char *progName, char *msg, int opt)
{
    if (msg != NULL && *msg != '\0')
        fprintf(stderr, "%s (-%c)\n", msg, (unsigned char)opt);
    fprintf(stderr, "\t Usage:%s [-a arg1] [-b arg2] [-c] [-d] arg3\n", progName);

    exit(EXIT_FAILURE);
}
