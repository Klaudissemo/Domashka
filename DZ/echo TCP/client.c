#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(){

    int sock;
    int server_port = 5546;
    char client_msg[100];
    struct sockaddr_in server_address;

    sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock < 0)
        {
            perror("socket");
            exit(1);
        }

    server_address.sin_family = AF_INET;    
    server_address.sin_port = htons(server_port);
    server_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    printf("This is client\n");
    
    if(connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("connect");
        exit(2);
    }
	while(1) {
        memset(client_msg, '\0', sizeof(client_msg));
		fgets (client_msg, 1024, stdin);
		send(sock, client_msg, sizeof(client_msg), 0);
		recv(sock, client_msg, sizeof(client_msg) , 0);
		printf("server response %s\n", client_msg);
	}	
    close(sock);
	
    

return 0;
};