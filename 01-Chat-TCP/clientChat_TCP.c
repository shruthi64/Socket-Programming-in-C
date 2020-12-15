#include<stdio.h>
#include<arpa/inet.h>
# define port 5000
void chat(int clisocket)
{
char buffer[100];
while(1)
{
printf("\nTo server:");
fgets(buffer,sizeof(buffer),stdin);
send(clisocket,buffer,sizeof(buffer),0);
recv(clisocket,buffer,sizeof(buffer),0);
printf("\tFrom server:%s",buffer);
if(strcmp(buffer,"bye\n")==0)
break;
}
}

void main()
{
int clisocket;
struct sockaddr_in serveraddr;
clisocket=socket(PF_INET,SOCK_STREAM,0);
if(clisocket>0)
printf("client socket created\n");
serveraddr.sin_family= PF_INET;
serveraddr.sin_port= htons(port);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
connect(clisocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
chat(clisocket);
close(clisocket);
}
