#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
# define port 5000
void main()
{
struct sockaddr_in serveraddr,newaddr;
int sersocket,newsocket,s,size;
char buffer[100];
sersocket=socket(PF_INET,SOCK_STREAM,0);
if(sersocket>0)
printf("server socket is created");
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
FILE *fp;
fp=fopen("p.txt","w");
if(fp==NULL)
{
printf("\nFile cannot be opened");
exit(0);
}
else
{
printf("\nFile opened successfully");
read(newsocket,buffer,100);
printf("\nData to be written on file-%s\n",buffer);
fprintf(fp,"%s\n",buffer);
write(newsocket, buffer, strlen(buffer)+1);
fclose(fp);
}
close(sersocket);
}
