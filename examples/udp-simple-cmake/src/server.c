/************************************************************************************
 *                                       SERVER.C                                   *
 * UDP server example.                                                              *
 ************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "common.h"

int main() {
	int sockfd;
	char buffer[MAXLEN];
	char *hello_message = "Hello from server";
	struct sockaddr_in server, client;

	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	memset(&server, 0, sizeof(server));
	memset(&client, 0, sizeof(client));

	// Fill in the server's information
	server.sin_family      = AF_INET; 	  // Address Family Internet IPv4
	server.sin_addr.s_addr = INADDR_ANY;  // Listen on all host's IP addresses
	server.sin_port        = htons(PORT); // Server's Port

	// Bind the socket with the server address (and occupy the given port)
	if (bind(sockfd, (const struct sockaddr *) &server, sizeof(server)) < 0)
	{
		perror("Bind failed.");
		exit(EXIT_FAILURE);
	}
	printf("Server bound to port %d. Waiting for client's message. Press [Ctrl-C] to interrupt.\n", PORT);

	// The server main loop
	for (;;) {
		int len, n;
		len = sizeof(client);

		// Blocking receive. Wait for the client's message.
		// The message is stored into 'buffer', the clien't addres into 'client'
		n = recvfrom(sockfd, (char *)buffer, MAXLEN, 0, ( struct sockaddr *) &client, &len);
		buffer[n] = '\0';

		printf("Client [%s] sent: '%s'\n", inet_ntoa(client.sin_addr), buffer);

		// Send the reply back to the client
		sendto(sockfd, (const char *)hello_message, strlen(hello_message), 0, (const struct sockaddr *) &client, len);
		printf("Reply to client sent.\n");
	}
	// NOT REACHED
	close(sockfd);
	return EXIT_SUCCESS;
}

/*
 * EOF
 */
