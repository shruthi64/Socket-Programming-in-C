#include<stdio.h>
#include<arpa/inet.h>
#include<string.h>
# define port 5000
void main()
{
struct sockaddr_in serveraddr,newaddr;
int sersocket,newsocket,s,size;
char buffer1[100],buffer2[100],buffer[100];
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
recv(newsocket,buffer1,1024,0);
printf("\ndata received is %s\n",buffer1);
if(strcmp(buffer1,"admin")==0)
{
recv(newsocket,buffer2,1024,0);
printf("data received is %s\n",buffer2);
if(strcmp(buffer2,"admin")==0)
strcpy(buffer,"\nCONFIRMED\n");
else
strcpy(buffer,"\nEnter valid password\n");
send(newsocket,buffer,sizeof(buffer),0);
}
else
strcpy(buffer,"\nEnter valid username\n");
send(newsocket,buffer,sizeof(buffer),0);
close(sersocket);
}
