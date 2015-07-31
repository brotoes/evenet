#include <stdlib.h>
#include <time.h>
#include "SPH.h"

void parse(char* message) {
    int* opcode = (int*) message;
    switch ((*opcode)) {
        case CHAT_SEND:
            send_chat(message+4);
            break;
        case CHANNEL_OPEN:
            open_channel(message+4);           
            break;
        case CHAT_CLOSE:
            close_chat(message+4);
            break;
        case CHANNEL_RESPONSE:
            handle_response(message+4);
            break;
    }
}

void close_chat(char* message) {
    struct chat_close close_data;
    close_data.chan_id = (int*) message;
    //TODO get sender of close message
    //TODO send message to all recipients
}

void send_chat(char* message) {
    struct chat_message chat_message;
    chat_message.chan_id = (int*) message;
    chat_message.length = (int*) message+4;
    chat_message.message = message+8;
    //TODO send message to recipients
}

void handle_response(char* message) {
    //TODO update accept/deny status
    //TODO get recipient hash from chan id
}
void open_channel(char* message) {
    struct chan_open opendata;
    opendata.rec_count = (int*) message;
    opendata.rec_list = malloc(opendata->rec_count*sizeof(char));
    for (int i=0; i<opendata->rec_count; i++) {
        opendata.rec_list[i] = (message+4)+(64*i);
    }
    struct chan_request chan_data;
    chan_data.open_data = opendata;
    srand(time());
    chan_data.chan_id = rand();
    //TODO enter channel into table
    //TODO reply to client with channel id
    //TODO send msg CHANNEL_REQUESTED to each recipient 
    
}
