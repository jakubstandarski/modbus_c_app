# Author: Jakub Standarski
# Date: 29.07.2020



#-----------------------------------------------------------------------------#
# APPLICATION SETTINGS #
#-----------------------------------------------------------------------------#

CLIENT_APP = modbus_client.c
SERVER_APP = modbus_server.c
BUILD_DIR = ./build



#-----------------------------------------------------------------------------#
# EXTRA SOURCE & HEADER FILES #
#-----------------------------------------------------------------------------#

SOURCE_DIR = ./source
EXTRA_SOURCE_FILES =

EXTRA_INCLUDE_DIR = ./include



#-----------------------------------------------------------------------------#
# THIRD PARTY HEADER FILES #
#-----------------------------------------------------------------------------#

MODBUS_DIR = /usr/local/include/modbus/



#-----------------------------------------------------------------------------#
# COMPILER SETTINGS #
#-----------------------------------------------------------------------------#

CC = gcc
CSTANDARD = -std=gnu11
COMPILER_OPTIMIZATION_LEVEL = O2
COMPILER_ERRORS_LEVEL = -Wall -Werror

CFLAGS =  $(CSTANDARD)
CFLAGS += $(COMPILER_ERRORS_LEVEL)
CFLAGS += $(COMPILER_OPTIMIZATION LEVEL)
CFLAGS += -I$(EXTRA_INCLUDE_DIR) -I$(MODBUS_DIR)



#-----------------------------------------------------------------------------#
# LINKER SETTINGS #
#-----------------------------------------------------------------------------#

LDFLAGS = -lmodbus

