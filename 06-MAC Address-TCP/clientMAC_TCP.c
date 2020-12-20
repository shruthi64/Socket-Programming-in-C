#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
# define port 5000
void main()
{
struct sockaddr_in serveraddr;
struct ifreq ifr;
char *iface = "eth0";
char *mac;
int sersocket,clisocket;
char IPaddr[100],mac_addr[32]={0};
clisocket=socket(PF_INET,SOCK_STREAM,0);
if(clisocket>0)
printf("\nclient socket created");
serveraddr.sin_family= PF_INET;
serveraddr.sin_port= htons(port);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
connect(clisocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
strcpy(IPaddr,inet_ntoa(serveraddr.sin_addr));
send(clisocket,IPaddr,sizeof(IPaddr),0);
printf("\nIP address of client sent to server");
ifr.ifr_addr.sa_family = PF_INET;
strncpy((char *)ifr.ifr_name , (const char *)iface , IFNAMSIZ-1);
ioctl(clisocket, SIOCGIFHWADDR, &ifr);
mac = (char *)ifr.ifr_hwaddr.sa_data;
sprintf((char *)mac_addr,(const char *)"%.2hhx:%.2hhx:%.2hhx:%.2hhx:%.2hhx:%.2hhx\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
send(clisocket,mac_addr,sizeof(mac_addr),0);
printf("\nMAC address of client sent to server\n");
close(clisocket);
}

