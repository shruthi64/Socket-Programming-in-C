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
FILE *f;
int words = 0;
char c;
f=fopen("read.txt","r");
while((c=getc(f))!=EOF)	//Counting No of words in the file
{
fscanf(f,"%s",buffer);
if(isspace(c)||c=='\t'||c==('.'))
words++;
}
printf("\nWords = %d \n",words);	
write(clisocket,&words, sizeof(int));
rewind(f);//sets to beginning of file
char ch;
while(ch!=EOF)
{
fscanf(f,"%s",buffer);
write(clisocket,buffer,100);
ch=fgetc(f);
}
printf("\nThe file was sent successfully\n");
close(clisocket);
}


