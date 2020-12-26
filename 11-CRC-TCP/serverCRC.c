#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
# define port 5000
int* getCRC(char dividend[],char divisor[],int dataSize, int divisorSize){
int n1 = dataSize, n2 = divisorSize;
int i,j,n[50],div[50],temp,q[20]; 
int *f=(int*)malloc(sizeof(int)*20);
for(i=0;i<n1+n2-1;i++){
if(dividend[i]=='1')
n[i]=1;
else
n[i]=0;
}
for(i=0;i<n2;i++){
if(divisor[i]=='1')
div[i]=1;
else
div[i]=0;
}
for(i=0;i<n1;i++){
temp=i;
if(n[i]==1){
for(j=0;j<n2;j++){
if(n[temp]==div[j]){
n[temp]=0;
f[j]=0;
}
else{
n[temp]=1;
f[j]=1;
}
temp++;
}
q[i]=1;
}
else
q[i]=0;
}
return f;
}
void main()
{
int sersocket,s;
struct sockaddr_in serveraddr;
struct sockaddr_in newaddr;
int newsocket;
int size;
char buffer[100],msg[100];
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
char divisor[4] = "1101";
recv(newsocket,buffer,1024,0);
int *remainder;
int dataSize = strlen(buffer) - strlen(divisor) + 1, divisorSize = strlen(divisor);
remainder = getCRC(buffer,divisor,dataSize,divisorSize);
int i;
for(i=1;i<divisorSize;i++){
if(remainder[i]!=0){
strcpy(msg,"Error\n");
break;
}
}
if(i==divisorSize)
strcpy(msg,"No error\n");
send(newsocket,msg,sizeof(msg),0);
close(sersocket);
}
