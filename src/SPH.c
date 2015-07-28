#include <stdlib.h>
#include <time.h>

void parse(char* message) {
    int* opcode = message;
    switch ((*opcode)) {
        case CHAT_SEND:
            send_chat(message+4);
            break;
        case CHANNEL_OPEN:
            open_channel(message+4);           
            break;
        case CHANNEL_RESPONSE:
            handle_response(message+4);
            break;
    }
}

void send_chat(char* message) {
    struct chat_message chat_message;
    chat_message.chan_id = message;
    chat_message.length = message+4;
    chat_message.message = message+8;
    //TODO send message to channel
}

void handle_response(char* message) {
    //TODO update accept/deny status
    //TODO get recipient hash from chan id
}
void open_channel(char* message) {
    struct chan_open opendata;
    opendata.rec_count = message;
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



