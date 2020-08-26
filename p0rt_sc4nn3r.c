#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
 
#define MAXCHAR 10

void port_scanner(struct sockaddr_in server ,int port){
    int fd ;
    fd = socket(AF_INET,SOCK_STREAM,0);

    if(connect(fd,(struct sockaddr *)&server,sizeof(server))>=0){

       printf("[#### PORT OPENED #####]------> %d\n",port);
       close(fd);
       return ;
        
    }

}

int main(int argc , char *argv[]) {

    if(argc != 2){
        fprintf(stderr,"<USAGE> %s <ip of the target>\n",argv[0]);
        exit(0);
    }
    struct sockaddr_in server ;

    int i , n =1000;
    int port ;
    char *ip = argv[1] ;
    server.sin_family = AF_INET ;
    
    server.sin_addr.s_addr = inet_addr(ip);
    for(i=1;i<n;i++){
    port = i ;
    server.sin_port = htons(port);
    port_scanner(server , port);

    }
    return 0 ;
}

