// A simple server example

#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>

int main(int argc, char* argv[])
{
    int sockfd;
    int connfd;
    struct sockaddr_in myaddr;
    char buffer[4096];
    char ipaddr[INET6_ADDRSTRLEN];

    if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0)
    {
        fprintf(stderr,"error creating socket\n");
        return -1;
    }

    memset(&myaddr,0,sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = INADDR_ANY;
    myaddr.sin_port = htons(8080);

    if(bind(sockfd,(struct sockaddr *)&myaddr,sizeof(myaddr))!=0)
    {
        fprintf(stderr,"error binding address|| missing permissions\n");
        return -1;
    }

    memset(&ipaddr,0,sizeof(ipaddr));
    inet_ntop(myaddr.sin_family,&myaddr.sin_addr,ipaddr,sizeof(ipaddr));
    printf("server ready to listen: %s\n",ipaddr);
    if(listen(sockfd,1)!=0)
    {
        fprintf(stderr,"liten error");
        return -1;
    }
    
    connfd = accept(sockfd,(struct sockaddr *)NULL,NULL);

    snprintf(buffer,sizeof(buffer),"Hello from server\n");
    write(connfd,buffer,strlen(buffer));
    
    close(connfd);

    return 0;
}
