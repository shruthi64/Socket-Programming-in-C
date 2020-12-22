#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
# define port 5000
void main()
{
struct sockaddr_in serveraddr;
int clisocket;
char buffer[100];
clisocket=socket(PF_INET,SOCK_STREAM,0);
if(clisocket>0)
printf("client socket created");
serveraddr.sin_family= PF_INET;
serveraddr.sin_port= htons(port);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
connect(clisocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("\nEnter data");
fgets(buffer,100,stdin); /*stdin = 0 , for standard input */
write(clisocket,buffer,strlen(buffer)+1);
close(clisocket);
}
