/*
 * Author: Jakub Standarski
 * Date: 02.08.2020
 *
 */

#ifndef COMMUNICATION_H
    #define COMMUNICATION_H



/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "status.h"

#include <modbus.h>

    

/*****************************************************************************/
/* PUBLIC FUNCTIONS PROTOTYPES */
/*****************************************************************************/

status_t allocate_mapping(modbus_mapping_t *modbus_mapping);

status_t communication_handler(modbus_t *modbus_context, uint8_t *request,
    modbus_mapping_t *modbus_mapping);

#endif /* COMMUNICATION_H */

