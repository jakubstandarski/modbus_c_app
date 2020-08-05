/*
 * Author: Jakub Standarski
 * Date: 02.08.2020
 *
 */



/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include <errno.h>
#include <modbus.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



/*****************************************************************************/
/* MAIN */
/*****************************************************************************/

int main(int argc, char *argv[])
{
    const char ip_address[] = "127.0.0.1";

    int tcp_port = 0;
    if (argc > 1) {
        tcp_port = atoi(argv[1]);
    } else {
        fprintf(stderr, "TCP port has not been provided!\n");
        fprintf(stderr, "Closing the server application...\n");
        return -1;
    }

    modbus_t *modbus_context = NULL;
    modbus_context = modbus_new_tcp(ip_address, tcp_port);
    if (modbus_context == NULL) {
        fprintf(stderr, "Initializing modbus context failed: %s\n",
            modbus_strerror(errno));
        return -1;
    }
    printf("Modbus context initialized succesfully:\t");
    printf("IP address: %s\t TCP port: %d\n", ip_address, tcp_port);

    modbus_mapping_t *modbus_mapping = NULL;
    modbus_mapping = modbus_mapping_new(0, 0, MODBUS_MAX_READ_REGISTERS, 0);
    if (modbus_mapping == NULL) {
        fprintf(stderr, "Failed to allocate the mapping: %s\n",
            modbus_strerror(errno));
        return -1;
    }
    printf("Mapping allocated successfully!\n");


    int incoming_connections_max = 1;
    while (1) {
        int listening_server_socket = -1;
        listening_server_socket = modbus_tcp_listen(modbus_context,
            incoming_connections_max);
        if (listening_server_socket == -1) {
            fprintf(stderr, "Creation of server listening socket failed: %s\n",
                modbus_strerror(errno));
            modbus_free(modbus_context);
            return -1;
        }
        printf("Server listening socket created successfully!\n");
        printf("Waiting for the client to connect...\n");

        int error_code = -1;
        error_code = modbus_tcp_accept(modbus_context,
            &listening_server_socket);
        if (error_code == -1) {
            fprintf(stderr, "Creation of client-server socket failed: %s\n",
                modbus_strerror(errno));
            modbus_free(modbus_context);
            return -1;
        }
        printf("Client-server socket created successfully!\n");
        close(listening_server_socket);


        uint8_t request[MODBUS_TCP_MAX_ADU_LENGTH] = {0};
        int request_length = -1;
        request_length = modbus_receive(modbus_context, request);
        if (request_length > 0) {
            printf("Indication request received successfully!\n");

            int response_length = -1;
            response_length = modbus_reply(modbus_context, request,
                request_length, modbus_mapping);
            if (response_length == -1) {
                fprintf(stderr, "Failed to send a response: %s\n",
                    modbus_strerror(errno));
                break;
            }
            printf("Reply sent successfully!\n");
        } else if (request_length == -1) {
            fprintf(stderr, "Failed to receive indication request: %s\n",
                modbus_strerror(errno));
        }
        
        printf("Closing connection with the client...\n\n");
        modbus_close(modbus_context);
    }

    return 0;
}

