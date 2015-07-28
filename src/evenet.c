#include <stdio.h>
#include <stdlib.h>
#include <config.h>
#include <libssh/libssh.h>

int main(int argc, char *argv[]) {
    get_conf_opt("server", "host");

    return 0;
    ssh_session session = ssh_new();
    ssh_channel channel;
    int rc;
    char *password;
    char buffer[20248];
    unsigned int nbytes;

    if (session == NULL) {
        exit(-1);
    }

    ssh_options_set(session, SSH_OPTIONS_HOST, "brocktoews.com");
    ssh_options_set(session, SSH_OPTIONS_USER, "brock");
    
    rc = ssh_connect(session);
    if (rc != SSH_OK) {
        fprintf(stderr, "Error connecting to host: %s\n",
            ssh_get_error(session));
        ssh_free(session);
        exit(-1);
    }

    password = getpass("Password: ");
    rc = ssh_userauth_password(session, NULL, password);
    if (rc != SSH_AUTH_SUCCESS) {
        fprintf(stderr, "Error authenticating with password: %s\n",
            ssh_get_error(session));
        ssh_disconnect(session);
        ssh_free(session);
        exit(-1);       
    }

    channel = ssh_channel_new(session);
    if (channel == NULL) {
        return SSH_ERROR;
    }

    rc = ssh_channel_open_session(channel);
    if (rc != SSH_OK) {
        return SSH_ERROR;
    }

    rc = ssh_channel_request_exec(channel, "ls");

    nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);

    printf ("%s\n", buffer);

    ssh_channel_send_eof(channel);
    ssh_channel_close(channel);
    ssh_channel_free(channel);

    ssh_disconnect(session);
    ssh_free(session);

    return 0;
}
