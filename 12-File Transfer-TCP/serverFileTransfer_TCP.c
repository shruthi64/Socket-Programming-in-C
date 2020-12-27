#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int ch=0;
int words;
fp=fopen("write.txt","w");
if(fp==NULL)
{
printf("\nFile cannot be opened");
exit(0);
}
else
{
printf("\nFile opened successfully\n");
read(newsocket,&words,sizeof(int));
while(ch!=words)
{
read(newsocket,buffer,100); 
fprintf(fp,"%s ",buffer);
ch++;
}
printf("The new file created is write.txt\n");
fclose(fp);
}
close(sersocket);
}


