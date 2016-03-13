// show ip addresses of a host given on command line

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(int argc, char* argv[])
{
    struct addrinfo hint, *res, *p;
    int status;
    char ipstr[INET6_ADDRSTRLEN];
    void *addr;

    if(argc != 2)
    {
        fprintf(stderr,"usage: showip HOSTNAME");
        return 1;
    }
    
    memset(&hint,0,sizeof(hint));
    hint.ai_family=AF_INET;
    hint.ai_socktype=SOCK_STREAM;

    if((status = getaddrinfo(argv[1],NULL,&hint,&res))!=0)
    {
        fprintf(stderr,"getaddrinfo: %s\n",gai_strerror(status));
        return 2;
    } 

    printf("IP addresses for %s:\n",argv[1]);

    for(p = res; p != NULL;p=p->ai_next)
    {
        struct sockaddr_in *ip= (struct sockaddr_in *)p->ai_addr;
        addr = &(ip->sin_addr);
        inet_ntop(p->ai_family,addr,ipstr,sizeof(ipstr));
        printf("%s\n",ipstr);
    }

    return 0;


}
