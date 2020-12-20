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
struct sockaddr_in serveraddr,newaddr;
int sersocket,newsocket,s,size;
char buffer[100];
sersocket=socket(PF_INET,SOCK_STREAM,0);
if(sersocket>0)
printf("\nserver socket is created");
serveraddr.sin_family= PF_INET;
serveraddr.sin_port= htons(port);
serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
s=bind(sersocket,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
if(s==0)
printf("\nbind success");
listen(sersocket,1);
size=sizeof(newaddr);
printf("\nserver ready");
newsocket=accept(sersocket,(struct sockaddr *)&newaddr,&size);
if(newsocket>0)
printf("\naccepted");
recv(newsocket,buffer,1024,0);
printf("\nIP address : %s",buffer);
recv(newsocket,buffer,1024,0);
printf("\nMAC address : %s\n",buffer);
close(sersocket);
}
