#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    char buffer[30];
    int sid = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in ser, cli;
    ser.sin_family = AF_INET;
    ser.sin_port = 3030;
    ser.sin_addr.s_addr = INADDR_ANY;

    bind(sid, (struct sockaddr *)&ser, sizeof(ser));
    int c = sizeof(cli);
    while (1)
    {
        memset(buffer, '\0', sizeof(buffer));
        recvfrom(sid, buffer, sizeof(buffer), 0, (struct sockaddr *)&cli, &c); // recieve data from client
        if (strcmp(buffer, "exit") == 0)
        {
            printf("Exiting server.....");
            break;
        }
        printf("Client: %s", buffer);
        printf("Server: ");
        fgets(buffer, sizeof(buffer), stdin);
        sendto(sid, buffer, sizeof(buffer), 0, (struct sockaddr *)&cli, sizeof(cli));
    }
}