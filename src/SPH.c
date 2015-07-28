#include <stdlib.h>
#include <string.h>
#include <time.h>
void parse(char* message) {
    int* opcode = message;
    switch ((*opcode)) {
        case CHANNEL_OPEN:
            open_channel(message+4);           
            break;
        case CHANNEL_RESPONSE:
            handle_response(message+4);
            break;
    }
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



