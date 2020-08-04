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

status_t allocate_mapping(modbus_mapping_t *modbus_mapping,
    int read_bits_max, int input_bits_max, int read_registers_max,
    int input_registers_max);

status_t communication_handler(modbus_t *modbus_context,
    modbus_mapping_t *modbus_mapping);

#endif /* COMMUNICATION_H */

