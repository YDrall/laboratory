// A simple client program to connect to a server given on command line
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, char *argv[])
{
    int client_sockfd;
    struct sockaddr_in servaddr;
    int n;
    char buffer[4096];

    if(argc!=2)
    {
        fprintf(stderr,"usage: client server_address\n");
        return -1;
    }

    if((client_sockfd = socket(AF_INET,SOCK_STREAM,0))<0)
    {
        fprintf(stderr,"error creating socket\n");
        return 1;
    }

    memset(&servaddr,0,sizeof(servaddr));

    servaddr.sin_family= AF_INET;
    servaddr.sin_port= htons(8080);
    
    if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<=0)
    {
        fprintf(stderr,"inet_pton error %s\n",argv[1]);
        return 2;
    }

    if(connect(client_sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))!=0)
    {
        fprintf(stderr,"error in connect\n");
        return 3;
    }

    while((n=read(client_sockfd,buffer,4096))>0)
    {
        fputs(buffer,stdout);
    }
    printf("process completed\n");

    return 0;

}
