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
#define MAXPOSTS 10
#define MAXBADWORDS 15
#define NTEAMS 4

char *clients[MAXCLIENTS];

char *posts[MAXPOSTS];
int post_index = 0;

char *canAdmin[MAXCLIENTS];

char *admin[MAXCLIENTS];
int adm_index = 0;

char *memeteam[MAXCLIENTS];
int meme_index = 0;

char *bestteam[MAXCLIENTS];
int best_index = 0;

char *cheatersteam[MAXCLIENTS];
int cheaters_index = 0;

char *badWords[MAXBADWORDS];


// verifica se val está no array arr[]
int valueinarray(char* val, char* arr[]) {
    for(int i = 0; i < MAXCLIENTS; i++) {
        if(!strcmp(val, arr[i]))
            return 1;
    }
    
    return 0;
}

// verifica se val é uma palavra imprópria
int isInBadWords(char* val) {
    for(int i = 0; i < MAXBADWORDS; i++) {
        if(!strcmp(val, badWords[i]))
            return 1;
    }

    return 0;
}

// verifica se val contém uma palavra imprópria
int hasBadWord(char* val) {
    char* word = strtok(val, " ");

    while(word != NULL) {
        if(isInBadWords(word))
            return 1;

        word = strtok(NULL, " "); 
    }

    return 0;
}

// remover string de outra string
char* remove_str(char* remove, char* from) {
    int sz = 0;
    while(remove[sz] != '\0') // tamanho da segunda palavra
        sz++;

    from += sz + 1; // remover segunda p

    return from;
}

// contar número de bytes de um ficheiro
long getNBytes(char* filename) {
    long count = 0;
    FILE* file = fopen(filename, "rb");

    if (file== NULL) return -1;
        fseek(file, 0, SEEK_END);

    count = ftell(file);

    fclose(file);

    return count;
}

// envia uma mensagem a todos os utilizadores exluindo aquele que enviou
void sendToAll(char* message, int index) {
    int i = 0;
    while(clients[i] != "0") {
        if(i != index)
            write(i + 4, message, strlen(message)+1);
        i++;
    }
}

// envia uma mensagem para o utilizador <user>
void sendToUser(char* user, char* message) {
    int i = 0;
    while(clients[i] != "0") {
        if(!strcmp(clients[i], user))
            break;
        i++;
    }
    write(i + 4, message, strlen(message));
}

// envia uma mensagem para a TAG <tag>
void sendToTag(char* tag, char* message, int sender) {
    if(!strcmp(tag, "ADMIN")) {
        for(int i = 0; i < adm_index; i++) {
            int j = 0;
            while(clients[j] != "0") {
                if(!strcmp(clients[j], admin[i]) && j != sender) {
                    write(j + 4, message, strlen(message));
                    break;
                }
                j++;
            }
        }
    }

    if(!strcmp(tag, "MEMETEAM")) {
        for(int i = 0; i < meme_index; i++) {
            int j = 0;
            while(clients[j] != "0") {
                if(!strcmp(clients[j], memeteam[i]) && j != sender) {
                    write(j + 4, message, strlen(message));
                    break;
                }
                j++;
            }
        }
    }

    if(!strcmp(tag, "BESTTEAM")) {
        for(int i = 0; i < best_index; i++) {
            int j = 0;
            while(clients[j] != "0") {
                if(!strcmp(clients[j], bestteam[i]) && j != sender) {
                    write(j + 4, message, strlen(message));
                    break;
                }
                j++;
            }
        }
    }

    if(!strcmp(tag, "CHEATERSTEAM")) {
        for(int i = 0; i < cheaters_index; i++) {
            int j = 0;
            while(clients[j] != "0") {
                if(!strcmp(clients[j], cheatersteam[i]) && j != sender) {
                    write(j + 4, message, strlen(message));
                    break;
                }
                j++;
            }
        }
    }
}

int process_client(int sock, char *clients[]) {
    int n;
    int index = sock - 4;
    char buf[BUFSIZE];

    n = read(sock, buf, BUFSIZE);


    if (n <= 0) {
        return 0; /* client closed socket */
    }

    char* first = strtok(strdup(buf), " "); // retira do buf a primeira palavra
    
    buf[n] = '\0';
    
    int sz = 0;
    char* aux = strdup(buf);
    aux = remove_str(first, aux);
    
    if(!strcmp(first, "HELLO")) {
        sz = 0;
        int i = 0;
        while(aux[i] != '\0') { // tamanho do nome
            if(aux[i] != ' ')
                sz++;
            i++;
        }

        if(valueinarray(aux, clients) || sz == 0 || clients[index] != "0") {
            char msg[BUFSIZE];
            sprintf(msg, "ERR NICK %s", aux);
            write(sock, msg, strlen(msg));
            return 1;
        }

        if(clients[index] == "0") {
            clients[index] = aux;
            char msg[BUFSIZE];
            sprintf(msg, "OK NICK %s", aux);
            write(sock, msg, strlen(msg));
            char* listTeams = "\nThese are the available teams/groups: \nADMIN\nMEMETEAM\nBESTTEAM\nCHEATERSTEAM\nYou can use the command SUB <team-name> to subscribe to a team.";
            write(sock, listTeams, strlen(listTeams));
            return 1;
        }
    }

    // MEMETEAM
    // BESTTEAM
    // CHEATERSTEAM
    // ADMIN

    if(!strcmp(first, "SUB")) {
        char* next = strtok(aux, " ");
        aux = remove_str(next, aux);

        if(!strcmp(next, "ADMIN")) {
            if(valueinarray(clients[index], canAdmin)) {
                if(valueinarray(clients[index], admin)) {
                    char* msg = "ERR ALREADY IN GROUP/TEAM";
                    write(sock, msg, strlen(msg));
                    return 1;
                }

                admin[adm_index++] = strdup(clients[index]);
                char* msg = "OK SUBBED ADMIN";
                write(sock, msg, strlen(msg));
                return 1;
            }

            char* msg = "ERR PERMITION DENIED";
            write(sock, msg, strlen(msg));
            return 1;
        }

        if(!strcmp(next, "MEMETEAM")) {
            if(valueinarray(clients[index], memeteam)) {
                char* msg = "ERR ALREADY IN GROUP/TEAM";
                write(sock, msg, strlen(msg));
                return 1;
            }

            memeteam[meme_index++] = clients[index];
            char* msg = "OK SUBBED MEMETEAM";
            write(sock, msg, strlen(msg));
            return 1;
        }

        if(!strcmp(next, "BESTTEAM")) {
            if(valueinarray(clients[index], bestteam)) {
                char* msg = "ERR ALREADY IN GROUP/TEAM";
                write(sock, msg, strlen(msg));
                return 1;
            }

            bestteam[best_index++] = clients[index];
            char* msg = "OK SUBBED BESTTEAM";
            write(sock, msg, strlen(msg));
            return 1;
        }

        if(!strcmp(next, "CHEATERSTEAM")) {
            if(valueinarray(clients[index], cheatersteam)) {
                char* msg = "ERR ALREADY IN GROUP/TEAM";
                write(sock, msg, strlen(msg));
                return 1;
            }

            cheatersteam[cheaters_index++] = clients[index];
            char* msg = "OK SUBBED CHEATERSTEAM";
            write(sock, msg, strlen(msg));
            return 1;
        }

        char* msg = "ERR GROUP/TEAM DOES NOT EXIST";
        write(sock, msg, strlen(msg));

        return 1;
    }

    if(!strcmp(first, "MSG")) {
        char* next = strtok(aux, " ");
        aux = remove_str(next, aux);

        if(!strcmp(next, "USER")) {
            // mensagem para outro cliente
            char* user = strtok(aux, " ");
            if(!valueinarray(user, clients)) { // se o cliente nao existir
                char* msg = "ERR MSG USER";
                write(sock, msg, strlen(msg));
                return 1;
            } else {
                char* msg = "OK MSG USER";
                write(sock, msg, strlen(msg));
            }

            printf("%s\n", buf);

            aux = remove_str(user, aux);

            if(hasBadWord(strdup(aux))) {
                char *err = "ERR MSG CONTAINS IMPROPER LANGUAGE";
                write(sock, err, strlen(err));
                return 1;
            }

            char message[BUFSIZE];
            sprintf(message, "TEXT %s USER %s", clients[index], aux);
            sendToUser(user, message);

        } else if(!strcmp(next, "GLOBAL")) {
            // mensagem para todos
            printf("%s\n", buf);

            if(hasBadWord(strdup(aux))) {
                char *err = "ERR MSG CONTAINS IMPROPER LANGUAGE";
                write(sock, err, strlen(err));
                return 1;
            }

            char* ok = "OK MSG GLOBAL";
            write(sock, ok, strlen(ok));

            char message[BUFSIZE]; 
            printf("!!! %s\n", aux);
            sprintf(message, "TEXT %s GLOBAL %s", clients[index], aux);
            sendToAll(message, index);

        } else if(!strcmp(next, "ADMIN")) {
            printf("%s\n", buf);

            char* ok = "OK MSG ADMIN";
            write(sock, ok, strlen(ok));

            char message[BUFSIZE];
            sprintf(message, "TEXT %s ADMIN %s", clients[index], aux);
            sendToTag("ADMIN", message, index);

        } else if(!strcmp(next, "MEMETEAM")) {
            printf("%s\n", buf);

            if(hasBadWord(strdup(aux))) {
                char *err = "ERR MSG CONTAINS IMPROPER LANGUAGE";
                write(sock, err, strlen(err));
                return 1;
            }

            char* ok = "OK MSG MEMETEAM";
            write(sock, ok, strlen(ok));

            char message[BUFSIZE];
            sprintf(message, "TEXT %s MEMETEAM %s", clients[index], aux);
            sendToTag("MEMETEAM", message, index);

        } else if(!strcmp(next, "BESTTEAM")) {
            printf("%s\n", buf);

            if(hasBadWord(strdup(aux))) {
                char *err = "ERR MSG CONTAINS IMPROPER LANGUAGE";
                write(sock, err, strlen(err));
                return 1;
            }

            char* ok = "OK MSG BESTTEAM";
            write(sock, ok, strlen(ok));

            char message[BUFSIZE];
            sprintf(message, "TEXT %s BESTTEAM %s", clients[index], aux);
            sendToTag("BESTTEAM", message, index);

        } else if(!strcmp(next, "CHEATERSTEAM")) {
            printf("%s\n", buf);

            if(hasBadWord(strdup(aux))) {
                char *err = "ERR MSG CONTAINS IMPROPER LANGUAGE";
                write(sock, err, strlen(err));
                return 1;
            }

            char* ok = "OK MSG CHEATERSTEAM";
            write(sock, ok, strlen(ok));

            char message[BUFSIZE];
            sprintf(message, "TEXT %s CHEATERSTEAM %s", clients[index], aux);
            sendToTag("CHEATERSTEAM", message, index);
        }
    }

    if(!strcmp(first, "POST")) {
        char* next = strtok(aux, " ");

        if(strcmp(next, "GLOBAL")) {
            char* ok = "ERR POST INVALID TAG";
            write(sock, ok, strlen(ok));
            return 1;
        } else {
            char* ok = "OK POST GLOBAL";
            write(sock, ok, strlen(ok));
        }
        
        aux = remove_str(next, aux);

        if(hasBadWord(strdup(aux))) {
            char *err = "ERR POST CONTAINS IMPROPER LANGUAGE";
            write(sock, err, strlen(err));
            return 1;
        }
        
        char post[BUFSIZE];
        sprintf(post, "%s -> %s", clients[index], strdup(aux));
        posts[post_index++] = strdup(post);
    }

    if(!strcmp(first, "READ")) {
        char* next = strtok(aux, " ");
        if(next == NULL || strcmp(next, "GLOBAL")) {
            char* ok = "ERR ALLPOSTS INVALID TAG";
            write(sock, ok, strlen(ok));
            return 1;
        } else if(post_index == 0) {
            char* ok = "ERR ALLPOSTS NO POSTS AVAILABLE";
            write(sock, ok, strlen(ok));
            return 1;
        } else {
            char ok[BUFSIZE];
            sprintf(ok, "OK ALL POSTS GLOBAL %d\n", post_index);
            write(sock, ok, strlen(ok));
        }

        for(int i = 0; i < post_index; i++) {
            char post[BUFSIZE];
            sprintf(post, "POST %d %s\n", i, posts[i]);
            write(sock, post, strlen(post));
        }
    }

    if(!strcmp(first, "FILE")) {
        char* next = strtok(aux, " ");
        if(!strcmp(next, "USER")) {
            aux = remove_str(next, aux);

            char* user = strtok(aux, " ");
            aux = remove_str(user, aux);

            char* filename = strtok(aux, " ");
            FILE* file = fopen(filename, "r");
            if(!file) {
                char ok[BUFSIZE];
                sprintf(ok, "ERR FILE NOT ACCEPTED %s", filename);
                write(sock, ok, strlen(ok));
                return 1;
            }

            aux = remove_str(filename, aux);
            
            long bytes = (long) atoi(strtok(aux, " "));
            if(bytes != getNBytes(filename) || bytes > BUFSIZE) {
                char ok[BUFSIZE];
                sprintf(ok, "ERR FILE BYTES %s", filename);
                write(sock, ok, strlen(ok));
                return 1;
            }

            char ok[BUFSIZE];
            sprintf(ok, "OK FILE USER %s", filename);
            write(sock, ok, strlen(ok));

            char send[BUFSIZE];
            sprintf(send, "FILEFROM %s USER %s %s %ld\n", clients[index], user, filename, bytes);
            sendToUser(user, send);

            char fileContents[BUFSIZE];
            fread(fileContents, 1, bytes, file);

            sendToUser(user, fileContents);
        }
    }
    return 1;
}

int main(int argc, char const *argv[]) { 
    int server_fd, new_socket; 
    struct sockaddr_in address;
    
    for(int i = 0; i < 10; i++) {
        clients[i] = "0";
        posts[i] = "0";
        admin[i] = "0";
        memeteam[i] = "0";
        bestteam[i] = "0";
        cheatersteam[i] = "0";
        canAdmin[i] = "0";
    }

    canAdmin[0] = "w0rmer";
    canAdmin[1] = "daniels";

    badWords[0] = "fuck";
    badWords[1] = "FUCK";
    badWords[2] = "Fuck";
    badWords[3] = "bitch";
    badWords[4] = "BITCH";
    badWords[5] = "Bitch";
    badWords[6] = "gay";
    badWords[7] = "GAY";
    badWords[8] = "Gay";
    badWords[9] = "cunt";
    badWords[10] = "CUNT";
    badWords[11] = "Cunt";
    badWords[12] = "shit";
    badWords[13] = "SHIT";
    badWords[14] = "Shit";

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
                        
                        char disconnect[BUFSIZE] = "";
                        strcat(disconnect, strdup(clients[i-4]));
                        strcat(disconnect, " disconnected.");
                        printf("%s\n", strdup(disconnect));
                        sendToAll(disconnect, i-4);

                        clients[i-4] = "0";
                    } else { /* already processed */ }
                }
            }
        }
    }
    return 0; 
} 
