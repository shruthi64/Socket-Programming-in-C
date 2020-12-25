#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
# define port 5000
int parityCheck(char buffer[])
{
int i,count=0;
for(i=0;i<strlen(buffer);i++)
if(buffer[i]=='1')
count++;
if(count%2==0)
return '0';
else
return '1';
}
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
int parity=parityCheck(buffer);
if(parity=='0')
strcpy(buffer,"\nNo error in data\n");
else
strcpy(buffer,"\nError in data\n");
send(newsocket,buffer,sizeof(buffer),0);
close(sersocket);
}
