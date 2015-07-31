#ifndef SPH_H
#define SPH_H

struct chan_open {
    int op_code = CHANNEL_OPEN;
    int* rec_count;
    char** rec_list;
};

struct chan_request {
    int op_code = CHANNEL_REQUESTED;
    struct chan_open open_data;
    int chan_id;
};

struct chat_message {
    int op_code = CHAT_SENT;
    int* chan_id;
    int* length;
    char* message;
};

struct chat_close {
    int op_code = CHAT_CLOSE;
    int* chan_id;
    char* closer_hash;
};

void parse(char*);
void close_chat(char*);
void send_chat(char*);
void handle_response(char*);
void open_channel(char*);
#endif