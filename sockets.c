/**********************************************************************
* Author:       Sandro Aguilar
* Date:         February 23, 2020
*
*
**********************************************************************/

#include  <stdio.h>
#include <sys/socket.h>


int main()
{
    // sock_fd returns the lowest file descriptor available
    // int socket_fd = socket(int domain, int type, int protocol);  // socket syntax
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        printf("You got socked!\n");
    }

    return 0;
}

