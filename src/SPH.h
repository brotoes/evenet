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

void parse(char*);
void handle_response(char*);
void open_channel(char*);
#endif
