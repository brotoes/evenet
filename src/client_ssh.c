#include <stdlib.h>
#include <libssh/libssh.h>
#include <stdio.h>

int connect(ssh_session *session) {
    ssh_session session = ssh_new();
    if (session == NULL) {
        return -1;
    }

    
}

int disconnect(ssh_session session) {
    ssh_free(session);
}
