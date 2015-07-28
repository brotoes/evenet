#include <stdlib.h>
#include <string.h>
#include <opcodes.h>
#include <server_protocol_handler.h>

void parse(char* message) {
    int* opcode = (int*)message;
    switch ((*opcode)) {
        case CHANNEL_OPEN:
            break;
        case CHAT_SEND:
            break;
    }
}

void channel_open (char *message) {
    int *rec_count = (int *)message + 4;
    char** rec_list = malloc((*rec_count)*sizeof(char));
    for (int i=0; i<(*rec_count); i++) {
        rec_list[i] = (message+4)+(64*i);
    }
    //TODO enter channel into table

    //TODO reply to client with channel id

    //TODO send msg CHANNEL_REQUESTED to each recipient 
}
