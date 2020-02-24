/********************************************************************************
* Author:       Sandro Aguilar
* Date:         February 23, 2020
*
*
********************************************************************************/

#include  <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>


int main()
{
    // sock_fd returns the lowest file descriptor available
    // int socket_fd = socket(int domain, int type, int protocol);  // socket syntax
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        perror("Hull breach: socket()");
        exit(1);
    }


    struct sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(7000);



    // int connect(int socket_fc, struct sockaddr* address, size_t address_size);
    if (connect( socket_fd, (strucdt sockaddr*)&serverAddress, sizeof(serverAddress)) )
    {
        perror("Hull breach: connect()");
        exit(1);
    }



    return 0;
}

