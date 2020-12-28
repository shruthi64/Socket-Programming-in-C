#include<stdio.h>
#include<arpa/inet.h>
#define port 4000
void main()
{
struct sockaddr_in serveraddr,newaddr;
int sersocket,s,size;
char buffer[100];
sersocket=socket(AF_INET,SOCK_DGRAM,0);
if(sersocket>0)
printf("\nServer socket created");
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(port);
serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
s=bind(sersocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(s==0)
printf("\nBind success");
size=sizeof(newaddr);
recvfrom(sersocket,buffer,1024,0,(struct sockaddr*)&newaddr,&size);
printf("\nString recieved:%s\n",buffer);
close(sersocket);
}

