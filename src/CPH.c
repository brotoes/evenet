#include "CPH.h"

void parse(char* message) {
    int* opcode = (int*) message;
    switch ((*opcode)) {
        case CHANNEL_OPEN:
            int* chan_id = (int*) message+4;
            //TODO save channel id for recipient
            break;
    }
}
