#include<stdio.h>
#include<arpa/inet.h>
#define port 4000
void findAge(int current_date, int current_month,int current_year,int birth_date,int birth_month, int birth_year)
{
int month[] = { 31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };
if (birth_date > current_date) {
current_date = current_date + month[birth_month - 1];
current_month = current_month - 1;
}
if (birth_month > current_month) {
current_year = current_year - 1;
current_month = current_month + 12;
}
int calculated_date = current_date - birth_date;
int calculated_month = current_month - birth_month;
int calculated_year = current_year - birth_year;
printf("Present Age\nYears: %d  Months: %d  Days: %d\n",calculated_year,calculated_month,calculated_date);
}
int main()
{
time_t timer;
struct tm* tm_info;
int days,months,years;
char day[3];
char month[3];
char year[5];
int dd,mm,yy;
time(&timer);
tm_info = localtime(&timer);
strftime(day, 3, "%d", tm_info);
strftime(month, 3, "%m", tm_info);
strftime(year, 5, "%Y", tm_info);
days= atoi(day);
months= atoi(month);
years= atoi(year);
printf("%d/%d/%d\n", months, days, years);
struct sockaddr_in serveraddr,newaddr;
int sersocket,s,size;
sersocket=socket(AF_INET,SOCK_DGRAM,0);
if(sersocket>0)
printf("\nServer socket created");
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(port);
serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
s=bind(sersocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(s==0)
printf("\nBind success");
size=sizeof(newaddr);
recvfrom(sersocket,&dd,1024,0,(struct sockaddr*)&newaddr,&size);
recvfrom(sersocket,&mm,1024,0,(struct sockaddr*)&newaddr,&size);
recvfrom(sersocket,&yy,1024,0,(struct sockaddr*)&newaddr,&size);
printf("\nString recieved:%d/%d/%d\n",dd,mm,yy);
findAge(days,months,years,dd,mm,yy); 
close(sersocket);
}


