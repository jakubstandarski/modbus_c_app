#!/bin/bash

#-----------------------------------------------------------------------------#
# DESCRIPTION #
#-----------------------------------------------------------------------------#

# The following script generates number of servers based on user input.
# Each server opens its own TCP port starting from 1502.
# Each subsequent server opens the TCP port larger by 1 than the previous one.



read -p "Enter number of servers to be opened: " number_of_servers

create_servers() {
    local tcp_port=1502
    for ((i=0;i<$1;i++))
    do
        gnome-terminal -- ./build/modbus_server $tcp_port
        ((tcp_port=tcp_port+1))
    done
}

create_servers $number_of_servers

