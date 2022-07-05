#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/types.h>

int main()
{
    struct hostent *list;
    const char* IP = "119.3.70.188";

    struct in_addr addr;
    addr.s_addr = inet_addr(IP);
    char str[30];

    list = gethostbyaddr(&addr, sizeof(struct in_addr), AF_INET);
    if(list==NULL) 
    {
        perror("gethostbyaddr");
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