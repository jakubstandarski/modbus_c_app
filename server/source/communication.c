/*
 * Author: Jakub Standarski
 * Date: 02.08.2020
 *
 */



/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "communication.h"
#include "status.h"

#include <errno.h>
#include <modbus.h>
#include <stdio.h>



/*****************************************************************************/
/* PUBLIC FUNCTIONS DEFINITIONS */
/*****************************************************************************/

status_t allocate_mapping(modbus_mapping_t *modbus_mapping)
{
    modbus_mapping = modbus_mapping_new(500, 500, 500, 500);
    if (modbus_mapping == NULL) {
        fprintf(stderr, "Failed to allocate the mapping: %s\n",
            modbus_strerror(errno));
        return status_error;
    }

    return status_success;
}



status_t communication_handler(modbus_t *modbus_context,
    modbus_mapping_t *modbus_mapping)
{
    uint8_t request[MODBUS_TCP_MAX_ADU_LENGTH] = {0};
    int request_length = -1;

    request_length = modbus_receive(modbus_context, request);
    if (request_length > 0) {
        int response_length = -1;
        response_length = modbus_reply(modbus_context, request, request_length,
            modbus_mapping);
        if (response_length == -1) {
            fprintf(stderr, "Sending the response failed: %s\n",
                modbus_strerror(errno));
            return status_error;
        } 
    } else if (request_length == -1) {
            fprintf(stdout, "Closing the connection: %s\n",
                modbus_strerror(errno));
            return status_error;
    }

    return status_success;
}

