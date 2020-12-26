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
struct sockaddr_in serveraddr;
int clisocket;
char buffer[100],msg[100],divisor[4] = "1101";
int n = strlen(divisor);
clisocket=socket(PF_INET,SOCK_STREAM,0);
if(clisocket>0)
printf("\nclient socket created");
serveraddr.sin_family= PF_INET;
serveraddr.sin_port= htons(port);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
connect(clisocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("\nData: ");
scanf("%s",buffer);
int dataSize = strlen(buffer);
int i;
for(i=dataSize;i<dataSize+n-2;i++)
buffer[i]='0';
buffer[i]='\0';
send(clisocket,buffer,sizeof(buffer),0);
recv(clisocket,msg,sizeof(msg),0);
printf("%s",msg);
close(clisocket);
}

