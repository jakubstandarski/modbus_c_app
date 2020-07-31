/*
 * Author: Jakub Standarski
 * Date: 31.07.2020
 *
 */



/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "status.h"

#include <errno.h>
#include <modbus.h>
#include <stdio.h>



/*****************************************************************************/
/* PUBLIC FUNCTIONS DEFINITIONS */
/*****************************************************************************/

status_t tcp_establish_connection(modbus_t *modbus_context,
    const char *ip_address, int tcp_port, int incoming_connections_max)
{
    modbus_context = modbus_new_tcp(ip_address, tcp_port);
    if (modbus_context == NULL) {
        fprintf(stderr, "Initialization of modbus context failed: %s\n",
            modbus_strerror(errno));
            return status_error;
    }

    int server_socket = -1;
    server_socket = modbus_tcp_listen(modbus_context,
        incoming_connections_max);
    if (server_socket == -1) {
        fprintf(stderr, "Creation of server socket failed: %s\n",
            modbus_strerror(errno));
            return status_error;
    }

    int error_code = -1;
    error_code = modbus_tcp_accept(modbus_context, &server_socket);
    if (error_code == -1) {
        fprintf(stderr, "Creation of a new server socket failed: %s\n",
            modbus_strerror(errno));
            return status_error;
    }

    return status_success;
}

