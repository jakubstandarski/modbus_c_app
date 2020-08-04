# Author: Jakub Standarski
# Date: 29.07.2020



#-----------------------------------------------------------------------------#
# CLIENT SOURCE & HEADER FILES #
#-----------------------------------------------------------------------------#

CLIENT_SOURCE_DIR = ./client/source/
CLIENT_INCLUDE_DIR = ./client/include/

CLIENT_MAIN_SOURCE_FILE = modbus_client.c
CLIENT_EXTRA_SOURCE_FILES = 



#-----------------------------------------------------------------------------#
# SERVER SOURCE & HEADER FILES #
#-----------------------------------------------------------------------------#

SERVER_SOURCE_DIR = ./server/source/
SERVER_INCLUDE_DIR = ./server/include/

SERVER_MAIN_SOURCE_FILE = modbus_server.c
SERVER_EXTRA_SOURCE_FILES = 



#-----------------------------------------------------------------------------#
# COMMON SOURCE & HEADER FILES #
#-----------------------------------------------------------------------------#

COMMON_SOURCE_DIR = ./common/source/
COMMON_INCLUDE_DIR = ./common/include/

COMMON_SOURCE_FILES =



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
COMMON_CFLAGS += -I$(COMMON_INCLUDE_DIR)

CLIENT_CFLAGS = -I$(CLIENT_INCLUDE_DIR)

SERVER_CFLAGS = -I$(SERVER_INCLUDE_DIR)



#-----------------------------------------------------------------------------#
# LINKER SETTINGS #
#-----------------------------------------------------------------------------#

LDFLAGS = -lmodbus



#-----------------------------------------------------------------------------#
# BUILD PROCEDURES #
#-----------------------------------------------------------------------------#

BUILD_DIR = ./build/
CLIENT_APP_BIN = $(addprefix $(BUILD_DIR), \
	$(strip $(basename $(CLIENT_MAIN_SOURCE_FILE))))
SERVER_APP_BIN = $(addprefix $(BUILD_DIR), \
	$(strip $(basename $(SERVER_MAIN_SOURCE_FILE))))


CLIENT_SOURCES = $(addprefix $(CLIENT_SOURCE_DIR), $(CLIENT_MAIN_SOURCE_FILE))
CLIENT_SOURCES += $(addprefix $(CLIENT_SOURCE_DIR), \
	$(CLIENT_EXTRA_SOURCE_FILES))


SERVER_SOURCES = $(addprefix $(SERVER_SOURCE_DIR), $(SERVER_MAIN_SOURCE_FILE))
SERVER_SOURCES += $(addprefix $(SERVER_SOURCE_DIR), \
	$(SERVER_EXTRA_SOURCE_FILES))

COMMON_SOURCES += $(addprefix $(COMMON_SOURCE_DIR), \
	$(COMMON_SOURCE_FILES))



all: $(CLIENT_APP_BIN) $(SERVER_APP_BIN)

$(CLIENT_APP_BIN): $(CLIENT_SOURCES) $(COMMON_SOURCES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(COMMON_CFLAGS) $(CLIENT_CFLAGS) $^ --output $@ $(LDFLAGS)

$(SERVER_APP_BIN): $(SERVER_SOURCES) $(COMMON_SOURCES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(COMMON_CFLAGS) $(SERVER_CFLAGS) $^ --output $@ $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR)

