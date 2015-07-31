#ifndef SPH_H
#define SPH_H

struct chan_open {
    int* rec_count;
    char** rec_list;
};

struct chan_request {
    struct chan_open open_data;
    int chan_id;
};

struct chat_message {
    int* chan_id;
    int* length;
    char* message;
};

struct chat_close {
    int* chan_id;
    char* closer_hash;
};

void parse(char*);
void close_channel(char*);
void send_chat(char*);
void handle_response(char*);
void open_channel(char*);
#endif
