#include <stdlib.h>
#include <string.h>

void parse(char* message) {
    int* opcode = message;
    switch ((*opcode)) {
        case CHANNEL_OPEN:
            open_channel(message+4);           
            break;
        case CHAT_SEND:
            break;
    }
}
void open_channel(char* message) {
    struct chan_open opendata;
    opendata.rec_count = message;
    opendata.rec_list = malloc(opendata->rec_count*sizeof(char));
    for (int i=0; i<(*rec_count); i++) {
        opendata.rec_list[i] = (message+4)+(64*i);
    }
    //TODO enter channel into table
    //TODO reply to client with channel id
    //TODO send msg CHANNEL_REQUESTED to each recipient 

}



