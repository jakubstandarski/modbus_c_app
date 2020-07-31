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
    const char *ip_address, int tcp_port)
{
    modbus_context = modbus_new_tcp(ip_address, tcp_port);
    if (modbus_context == NULL) {
        fprintf(stderr, "Initialization of modbus context failed: %s\n",
            modbus_strerror(errno));
            return status_error;
    }

    int error_code;
    error_code = modbus_connect(modbus_context);
    if (error_code == -1) {
        fprintf(stderr, "Modbus connection failed: %s\n",
            modbus_strerror(errno));
            modbus_free(modbus_context);
            return status_error;
    }

    return status_success;
}

