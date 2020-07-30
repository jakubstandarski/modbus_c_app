# Author: Jakub Standarski
# Date: 29.07.2020



#-----------------------------------------------------------------------------#
# CLIENT SOURCE & HEADER FILES #
#-----------------------------------------------------------------------------#

CLIENT_APP = modbus_client.c

CLIENT_EXTRA_SOURCE_DIR = ./client/source
CLIENT_EXTRA_INCLUDE_DIR = ./client/include
CLIENT_EXTRA_SOURCE_FILES =



#-----------------------------------------------------------------------------#
# SERVER SOURCE & HEADER FILES #
#-----------------------------------------------------------------------------#

SERVER_APP = modbus_server.c

SERVER_EXTRA_SOURCE_DIR = ./server/source
SERVER_EXTRA_INCLUDE_DIR = ./server/include
SERVER_EXTRA_SOURCE_FILES =



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

COMMON_CFLAGS =  $(CSTANDARD)
COMMON_CFLAGS += $(COMPILER_ERRORS_LEVEL)
COMMON_CFLAGS += $(COMPILER_OPTIMIZATION LEVEL)
COMMON_CFLAGS += -I$(MODBUS_DIR)

CLIENT_CFLAGS = -I$(CLIENT_EXTRA_INCLUDE_DIR)

SERVER_CFLAGS = -I$(SERVER_EXTRA_INCLUDE_DIR)



#-----------------------------------------------------------------------------#
# LINKER SETTINGS #
#-----------------------------------------------------------------------------#

LDFLAGS = -lmodbus



#-----------------------------------------------------------------------------#
# BUILD PROCEDURES #
#-----------------------------------------------------------------------------#

BUILD_DIR = ./build

