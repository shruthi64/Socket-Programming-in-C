#include<stdio.h>
#include<arpa/inet.h>
#define port 4000
int main()
{
int dd,mm,yy;
struct sockaddr_in serveraddr,;
int clisocket;
clisocket=socket(AF_INET,SOCK_DGRAM,0);
if(clisocket>0)
printf("\nClient socket created");
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(port);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
printf("\nEnter date (dd/mm/yyyy) format:");
scanf("%d/%d/%d",&dd,&mm,&yy);
sendto(clisocket,&dd,sizeof(dd),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
sendto(clisocket,&mm,sizeof(mm),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
sendto(clisocket,&yy,sizeof(yy),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
close(clisocket);
}


