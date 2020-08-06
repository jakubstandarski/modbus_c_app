#!/bin/bash

#-----------------------------------------------------------------------------#
# DESCRIPTION #
#-----------------------------------------------------------------------------#

# The following script generates number of servers based on user input.
# Each server opens its own TCP port starting from 1502.
# Each subsequent server opens the TCP port larger by 1 than the previous one.



#-----------------------------------------------------------------------------#
# FUNCTIONS DEFINITIONS #
#-----------------------------------------------------------------------------#

check_if_build_exists() {
    if [ ! -d ./build/ ]; then
        make all
    fi
}


get_number_of_servers() {
    echo
    read -p "Enter number of servers to be opened: " number_of_servers
}


create_servers() {
    local tcp_port=1502
    for ((i=0;i<$1;i++))
    do
        gnome-terminal -- ./build/modbus_server $tcp_port
        ((tcp_port=tcp_port+1))
    done
}



#-----------------------------------------------------------------------------#
# SCRIPT EXECUTION #
#-----------------------------------------------------------------------------#

check_if_build_exists
get_number_of_servers
create_servers $number_of_servers

