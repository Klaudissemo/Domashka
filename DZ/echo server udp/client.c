#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main () 
{

    int socket_desc; 
    struct sockaddr_in server_addr;
    char client_msg[1000], server_msg[1000];
    int server_struct_length = sizeof(server_addr);


    //Create UDP Socket
    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if(socket_desc < 0) {
        perror("socket");
		exit(1);
    }
    printf("Socket created successfully\n");


    //Set port and IP
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7777);
    server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

for (;;)
{

    //Clean buffers msg
    memset(server_msg, '\0', sizeof(server_msg));
    memset(client_msg, '\0', sizeof(client_msg));


    //Get input from the user
    printf("Enter message: ");
    gets(client_msg);
    

    //Send the message to server:
    if(sendto(socket_desc, client_msg, strlen(client_msg), 0,
         (struct sockaddr*) &server_addr, server_struct_length) < 0){
        perror("sendto");
		exit(1);
    }

    if (strcmp(client_msg, "stop") == 0 || strcmp(client_msg, "Stop") == 0)
    {
        close(socket_desc);
        return 0;
    }

    //Receive the server's response
    if(recvfrom(socket_desc, server_msg, sizeof(server_msg), 0,
         (struct sockaddr*) &server_addr, &server_struct_length) < 0){
        perror("recvfrom");
		exit(3);
    }

    printf("Server's response: %s\n", server_msg);

}
    //Close the socket
    close(socket_desc);
    
    return 0;
}