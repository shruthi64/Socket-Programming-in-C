#include<stdio.h>
#include<arpa/inet.h>
# define port 5000
void chat(int newsocket)
{
char buffer[100];
while(1)
{
recv(newsocket,buffer,sizeof(buffer),0);
printf("\nFrom client:%s",buffer);
if(strcmp(buffer,"bye\n")==0)
break;
printf("\tTo client:");
fgets(buffer,sizeof(buffer),stdin);
send(newsocket,buffer,sizeof(buffer),0);
}
}
void main()
{
struct sockaddr_in serveraddr,newaddr;
int sersocket,newsocket,s,size;
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
printf("\naccepted\n");
chat(newsocket);
close(newsocket);
}
