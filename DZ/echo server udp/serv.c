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
    struct sockaddr_in server_addr, client_addr;
    char client_msg[1000], server_msg[1000];
    int client_struct_length = sizeof(client_addr);


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
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);


    //Bind to the set port and IP
    
    if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0 ) {
        perror("bind");
		exit(2);
    }
 
    printf("Done with binding\n");
    
    printf("Listening for incoming messages...\n\n");

for (;;)
{
    //Clean buffers msg
    memset(server_msg, '\0', sizeof(server_msg));
    memset(client_msg, '\0', sizeof(client_msg));

    //Receive client's message
    if(recvfrom(socket_desc, client_msg, sizeof(client_msg), 0,
           (struct sockaddr*) &client_addr, &client_struct_length) < 0){
        perror("recvorm");
		exit(3);
    }

     if (strcmp(client_msg, "stop") == 0 || strcmp(client_msg, "Stop") == 0)
    {
        printf("The command %s was received from the user IP: %s and port: %i\n", 
        client_msg, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        close(socket_desc);
        return 0;
    }

    printf("Received message from IP: %s and port: %i\n",
        inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
   
    printf("Msg from client: %s\n", client_msg);

    printf("Add at the end of 1...  \n");

    client_msg[strlen(client_msg)] = '1';

    printf("we send the resulting message %s back\n", client_msg);
    
    //Respond to client
    strcpy(server_msg, client_msg);
    /*printf("%d\n", strlen(server_msg));
    server_msg[strlen(server_msg)] = 1;*/
    if (sendto(socket_desc, server_msg, strlen(server_msg), 0,
         (struct sockaddr*) &client_addr, client_struct_length) < 0){
        perror("strcpy");
        exit(4);
    }
}
    
    //Close the socket
    close(socket_desc);
    
    return 0;
    
}