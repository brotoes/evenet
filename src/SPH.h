#ifndef SERVER_PROTOCOL_HANDLER_H
#define SERVER_PROTOCOL_HANDLER_H

struct chan_open {
    int* rec_count;
    char** rec_list;
};

void parse(char*);
void open_channel(char*);
#endif
