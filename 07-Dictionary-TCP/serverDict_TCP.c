#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
# define port 5000
void main()
{
struct sockaddr_in serveraddr,newaddr;
int sersocket,newsocket,s,size;
int i,c=0;
char buffer[100],word[100],antonym[100];
char dictionary[7][3][100]={"consider", "deem to be","disregard","minute" , "infinitely or immeasurably small","significant","accord" , "concurrence of opinion","withhold","commit" ,"perform an act,usually with a negative connotation","abstain","utter", "without qualification","partial","zealot", "a fervent and even militant proponent of something","moderate","wanton","a lewd or lascivious person","justifiable"};
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
printf("\nWord to be searched : %s\n",buffer);
for(i=0;i<7;i++)
{
if(strcmp(buffer,dictionary[i][0])==0)
{
strcpy(word,dictionary[i][1]);
send(newsocket,word,sizeof(word),0);
strcpy(antonym,dictionary[i][2]);
send(newsocket,antonym,sizeof(antonym),0);
}
else
c++;
}
if(c==7){
strcpy(word,"Word not found in dictionary");
send(newsocket,word,sizeof(word),0);
}
close(sersocket);
}
