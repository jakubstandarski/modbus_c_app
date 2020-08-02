/*
 * Author: Jakub Standarski
 * Date: 02.08.2020
 *
 */



/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "tcp_connection.h"

#include <errno.h>
#include <modbus.h>
#include <stdio.h>



/*****************************************************************************/
/* MAIN */
/*****************************************************************************/

int main(void)
{
    modbus_t *modbus_context = NULL;
    const char ip_address[] = "127.0.0.1";
    int tcp_port = 1502;
    int incoming_connections_max = 1;

    status_t status;
    status = tcp_establish_connection(modbus_context, ip_address, tcp_port,
        incoming_connections_max);
    if (status != status_success) {
        modbus_free(modbus_context);
        return -1;
    }

    modbus_close(modbus_context);
    modbus_free(modbus_context);
    return 0;
}

