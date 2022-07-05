#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

int main()
{
    const char* name = "www.bilibili.com";
    struct hostent *list;
    list = gethostbyname(name);
    char str[30]={0};
    if(list== NULL )
    {
       perror("gethostbyname");
       exit(EXIT_FAILURE);
    }

    printf("name: %s\n",list->h_name);
    printf("addrtype: %d\n",list->h_addrtype);
    printf("length: %d\n",list->h_length);
    char **ap,**lp;
    printf("\naliases list\n");
    for(ap=list->h_aliases; *ap!=NULL; ap++)
        printf("\t%s\n", *ap);
    printf("\naddress list\n");
    for(lp=list->h_addr_list; *lp!=NULL; lp++)
         printf("\t%s\n", inet_ntop(list->h_addrtype,*lp,str,30));
}