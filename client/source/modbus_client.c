/*
 * Author: Jakub Standarski
 * Date: 31.07.2020
 *
 */



/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "status.h"
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

    int tcp_port = 0;
    printf("Input TCP port number: ");
    scanf("%d", &tcp_port);

    status_t status;
    status = tcp_establish_connection(modbus_context, ip_address, tcp_port);
    if (status != status_success) {
        modbus_free(modbus_context);
        return -1;
    }

    uint16_t registers_table[MODBUS_MAX_READ_REGISTERS] = {0};
    int registers_read_count = -1;
    registers_read_count = modbus_read_registers(modbus_context, 0,
        MODBUS_MAX_READ_REGISTERS, registers_table);
    if (registers_read_count == -1) {
        fprintf(stderr, "Reading registers failed: %s\n",
            modbus_strerror(errno));
    }
    printf("Register value: %u\n", registers_table[0]);
    
    modbus_close(modbus_context);
    modbus_free(modbus_context);
    return 0;
}

