/********************************************************************************
* Author:       Sandro Aguilar
* Date:         February 23, 2020
* Description:  This short program is to test some of the common features of
*               socket programming.
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
    struct hostent* serverHostInfo;

    serverHostInfo = gethostbyname("www.oregonstate.edu");
    if (serverHostInfo == NULL)
    {
        fprintf(stderr, "could not resolve server host name\n");
        exit(1);
    }


    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(80);
    serverAddress.sin_addr.s_addr = inet_addr("192.168.1.1");


    memcpy( (char*)&serverAddress.sin_addr.s_addr, (char*)serverHostInfo->h_addr, serverHostInfo->h_length );



    // int connect(int socket_fc, struct sockaddr* address, size_t address_size);
    if (connect( socket_fd, (strucdt sockaddr*)&serverAddress, sizeof(serverAddress)) )
    {
        perror("Hull breach: connect()");
        exit(1);
    }


    // ssize_t sent( int socket_fd, void *message, size_t message_size, int flags );
    //ssize_t recv( int socket_fd, void *buffer, size_t buffer_size, int flags );




    return 0;
}

