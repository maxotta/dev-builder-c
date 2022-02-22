/************************************************************************************
 *                                       CLIENT.C                                   *
 * UDP client example.                                                              *
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

int main(int argc, char **argv) {
	int    sockfd;
	char   buffer[MAXLEN];
	char  *hello_message = "Hello from client !";
	struct sockaddr_in server;
	in_addr_t server_address;

	if (argc != 2) {
		printf("Usage: %s <IP v4 address>\n", argv[0]);
		exit(1);
	}

	// Convert dotted quad notation to a sockaddr_in address structure
	if ((server_address = inet_addr(argv[1])) < 0) {
		printf("Invalid address '%s' !\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// Create a socket file descriptor
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("Socket creation failed !\n");
		exit(EXIT_FAILURE);
	}

	// Fill in the server information
	server.sin_family      = AF_INET;            // Address Family Internet IPv4
	server.sin_port        = htons(PORT);        // Server's Port
	server.sin_addr.s_addr = server_address;     // Server's Address

	int n, len;

	// Send the packet to the server
	sendto(sockfd, (const char *)hello_message, strlen(hello_message), 0, (const struct sockaddr *) &server, sizeof(server));
	printf("Hello message sent, waiting for answer. Press [Ctrl-C] to interrupt.\n");

	// Blocking receive. Wait for the server's answer
	n = recvfrom(sockfd, (char *)buffer, MAXLEN, 0, (struct sockaddr *) &server, &len);
	buffer[n] = '\0';

	printf("Server [%s] replied: '%s'\n", inet_ntoa(server.sin_addr), buffer);

	close(sockfd);
	return EXIT_SUCCESS;
}

/*
 * EOF
 */
