#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <time.h>

#define PORT 1234 
#define BUFSIZE 256
#define MAXCLIENTS 10

char *clients[MAXCLIENTS];

int valueinarray(char* val, char* arr[])
{
    int i;
    for(i = 0; i < MAXCLIENTS; i++)
    {
        if(!strcmp(val, arr[i])) {
            return 1;
        }    
    }
    
    return 0;
}

void sendToAll(char* message) {
    int i = 0;
    while(clients[i] != "0") {
        write(i + 4, message, strlen(message)+1);
        i++;
    }
}

void sendToUser(char* user, char* message) {
    int i = 0;
    while(clients[i] != "0") {
        if(!strcmp(clients[i], user))
            break;
        i++;
    }
    write(i + 4, message, strlen(message)+1);
}

int process_client(int sock, char *clients[]) {
    int n;
    int index = sock - 4;
    char buf[BUFSIZE];

    n = read(sock, buf, BUFSIZE);

    if (n <= 0) {
        return 0; /* client closed socket */
    }
    
    buf[n] = '\0';

    if(clients[index] == "0") {
        clients[index] = strdup(buf);
        
        return 1;
    }

    char* user = strtok(strdup(buf), " ");
    
    int isNick = valueinarray(user, clients); // verifica se a primeira string é um nome de utilizador

    if(isNick) {
        // mensagem para outro cliente
        printf("- %s\n", buf);

        char message[BUFSIZE] = "- ";
        strcat(message, clients[index]);
        strcat(message, " ");
        
        int sz = 0;
        int j = 0;

        char result[BUFSIZE];
        char* aux = strdup(buf);

        char* token = strtok(aux, " ");

        while(token[sz] != '\0') { // tamanho do nome
            sz++;
        }

        for(int i = sz + 1; aux[i] != '\0'; i++) {
            result[j] = aux[i];
            j++;
        }

        strcat(message, result);
        sendToUser(user, message);

    } else {
        // mensagem para todos
        printf("+ %s \n", buf);
        
        char message[BUFSIZE] = "+ ";
        strcat(message, buf);
        sendToAll(message);
    }

    return 1;
}

int main(int argc, char const *argv[]) { 
    int server_fd, new_socket; 
    struct sockaddr_in address;
    
    for(int i = 0; i < 10; i++) {
        clients[i] = "0";
    }

    int opt = 1;      // for setsockopt() SO_REUSEADDR, below
    int addrlen = sizeof(address);
    int n, i;
    
    char buffer[BUFSIZE];

    fd_set master, read_fds;
    int fdmax;
    
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 1300 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
        perror("setsockopt failed"); 
        exit(EXIT_FAILURE); 
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Bind the socket to the network address and port
    if (  bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0  ) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    if (listen(server_fd, 3) < 0) { 
        perror("listen failed"); 
        exit(EXIT_FAILURE); 
    }

    FD_ZERO(&master);
    FD_ZERO(&read_fds);
    FD_SET(server_fd, &master);

    fdmax = server_fd;
    
    // Main loop
    while (1) {
        read_fds = master;

        select(fdmax+1, &read_fds, NULL, NULL, NULL);

        for (i = 0; i <= fdmax; i++) {
            
            if (FD_ISSET(i, &read_fds)) {
                
                if (i == server_fd) { // New conection, accept() it
                    
                    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) { 
                        perror("accept failed");
                        exit(EXIT_FAILURE); 
                    }
                    printf("Client connected.\n");
                    
                    if (new_socket > fdmax) {
                        fdmax = new_socket;
                    }

                    FD_SET(new_socket, &master);

                } else { // "Old" client sent data, read() it

                    if (process_client(i, clients) == 0) { // client close()d
                        FD_CLR(i, &master);
                        close(i);
                        printf("%s disconnected.\n", clients[i-4]);
                    } else { /* already processed */ }
                }
            }
        }
    }
    return 0; 
} 
