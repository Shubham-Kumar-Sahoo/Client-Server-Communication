#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main()
{
    char buffer[100];
    int sid = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in ser, cli;
    ser.sin_family = AF_INET;
    ser.sin_port = 3030;
    ser.sin_addr.s_addr = INADDR_ANY;
    if(bind(sid,(struct sockaddr*)&cli, sizeof(cli)));
            int c=sizeof(ser);
            while(1){
                printf("Client: ");
                fgets(buffer,sizeof(buffer),stdin);
                sendto(sid,buffer, strlen(buffer), 0,(const struct sockaddr *)&ser, sizeof(ser)); //send to server
                if (strcmp(buffer, "exit") == 0)
                {
                    printf("Exiting server.....");
                    break;
                }
                memset(buffer, '\0', sizeof(buffer));
                recvfrom(sid, buffer, sizeof(buffer), 0, (struct sockaddr *)&ser, &c);
                printf("Server: %s",buffer);
            }
}