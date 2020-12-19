#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
# define port 5000
void main()
{
struct sockaddr_in serveraddr;
int sersocket,clisocket;
char IPaddr[100];
clisocket=socket(PF_INET,SOCK_STREAM,0);
if(clisocket>0)
printf("\nclient socket created");
serveraddr.sin_family= PF_INET;
serveraddr.sin_port= htons(port);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
connect(clisocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
strcpy(IPaddr,inet_ntoa(serveraddr.sin_addr));
send(clisocket,IPaddr,sizeof(IPaddr),0);
printf("\nIP address of client sent to server\n");
close(clisocket);
}
