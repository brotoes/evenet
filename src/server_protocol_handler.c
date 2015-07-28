#include <stdlib.h>
#include <string.h>

void parse(char* message) {
    int* opcode = message;
    switch ((*opcode)) {
        case CHANNEL_OPEN:
            int* rec_count = message+4;
            char** rec_list = malloc((*rec_count)*sizeof(char));
            for (int i=0; i<(*rec_count); i++) {
                rec_list[i] = (message+4)+(64*i);
            }
            //TODO enter channel into table

            //TODO reply to client with channel id

            //TODO send msg CHANNEL_REQUESTED to each recipient 

            
            break;
        case CHAT_SEND:
            break;
    }
}
