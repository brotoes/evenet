#include <opcodes.h>
#include <CPH.h>

void parse(char* message) {
    int* opcode = (int*) message;
    switch ((*opcode)) {
        case CHANNEL_OPEN:
            //TODO save channel id for recipient
            channel_open(message);
            break;
    }
}

void channel_open(char * message) {
    int* chan_id = (int*)message + 4;
}
