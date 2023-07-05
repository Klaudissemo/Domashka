#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include "mylib.h"
#include "mylib.c"


int main(int argc, char *argv[]){

    int SERVER_PORT = 5546;
    
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;


    server_address.sin_port = htons(SERVER_PORT);

	server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    int listener = socket(AF_INET, SOCK_STREAM, 0);
	if(listener < 0) {
		perror("socket");
		exit(1);
    }
    
    if(bind(listener, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("bind");
        exit(2);
    }

    if(listen (listener, 100) < 0) {
		perror("listen");
		exit(3);
	}	
	printf("Server listening on port %d\n", ntohs(server_address.sin_port));

    while(1) {
		void* sock;
		
		sock = accept(listener, NULL, NULL);
		if(sock < 0) {
            perror("accept");
            exit(6);
        }
		pthread_t thread_id;
		int ret = pthread_create(&thread_id, NULL, connection, (void*) sock);
		if(ret != 0) {
			printf("Error from pthread: %d\n", ret);
			exit(4);
		}
		printf("Client connected to %ld socket\n", sock);
	}
	return 0;
}