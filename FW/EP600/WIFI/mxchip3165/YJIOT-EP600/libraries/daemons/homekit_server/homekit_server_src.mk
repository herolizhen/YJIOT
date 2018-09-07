#
#  UNPUBLISHED PROPRIETARY SOURCE CODE
#  Copyright (c) 2016 MXCHIP Inc.
#
#  The contents of this file may not be disclosed to third parties, copied or
#  duplicated in any form, in whole or in part, without the prior written
#  permission of MXCHIP Corporation.
#

NAME := Lib_HomeKit_Server

HK_SERVER_DIR := src

$(NAME)_SOURCES := 	\
					$(HK_SERVER_DIR)/HomeKitBonjour.c \
                    $(HK_SERVER_DIR)/HomeKitHTTPUtils.c \
                    $(HK_SERVER_DIR)/HomeKitPairProtocol.c \
                    $(HK_SERVER_DIR)/HomeKitServer.c
					
	

$(NAME)_INCLUDES := $(BTEINCLUDES)
