#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h> 
#include <unistd.h>
#include<string.h> 
#include<strings.h>
#include <arpa/inet.h>
#include<math.h>
//#define buffsize  150
void main()
{
int b,sockfd,sin_size,con,n,len;
//char buff[256];
double angle,result;
char op,ch;
FILE *fp;
if((sockfd=socket(AF_INET,SOCK_STREAM,0))>0)
printf("socket created sucessfully\n");
//printf("%d\n", sockfd);
struct sockaddr_in servaddr;
 
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=6666;
 
sin_size = sizeof(servaddr);
if((con=connect(sockfd,(struct sockaddr *) &servaddr, sin_size))==0);
 //initiate a connection on a socket
printf("connect sucessful\n");

write(sockfd,"HELLO FROM CLIENT", sizeof("HELLO FROM CLIENT"));
 
//
//2 To receive file
fp = fopen("b.txt", "w");
read(sockfd,&ch,sizeof(ch));
while(ch!=EOF)
{		
	fputc(ch,fp);
	read(sockfd,&ch,sizeof(ch));
}
printf("FILE RECEIVED\n");
fclose(fp);

printf("Enter operation:\n 1:sin \n 2:cos\n 3:tan \n ");
scanf("%c",&op);
printf("Enter angle in degree:");
scanf("%lf",&angle);
 
write(sockfd,&op,1);
 
write(sockfd,&angle,sizeof(angle));
 
read(sockfd,&result,sizeof(result)); 
printf("\n Operation result from server=%lf\n",result);  
close(sockfd);
}
 