#include <stdlib.h>
#include <libssh/libssh.h>
#include <stdio.h>

int srv_connect(ssh_session *session) {
    *session = ssh_new();
    if (session == NULL) {
        return -1;
    }

    
    return 0;
}

int srv_disconnect(ssh_session session) {
    ssh_free(session);
    return 0;
}
