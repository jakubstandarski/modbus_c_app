/*
 * Author: Jakub Standarski
 * Date: 31.07.2020
 *
 */

#ifndef TCP_CONNECTION_H
    #define TCP_CONNECTION_H


/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "status.h"

#include <modbus.h>



/*****************************************************************************/
/* PUBLIC FUNCTIONS PROTOTYPES */
/*****************************************************************************/

status_t tcp_establish_connection(modbus_t *modbus_context,
    const char *ip_address, int tcp_port);

#endif /* TCP_CONNECTION_H */

