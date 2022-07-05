#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    //打开协议文件
    setprotoent(1);
    //读行
    struct protoent *cur = getprotoent();
    fprintf(stdout,
            "\n\tprotocol_name\tprotool_number\tprotocol_aliases\n");
    while (cur != NULL)
    {
        fprintf(stdout, "\t%8s\t%8d\t%8s\n",
                cur->p_name, cur->p_proto, *(cur->p_aliases));

        cur = getprotoent();
    }
    endprotoent();
}