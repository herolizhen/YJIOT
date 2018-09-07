#
#  UNPUBLISHED PROPRIETARY SOURCE CODE
#  Copyright (c) 2016 MXCHIP Inc.
#
#  The contents of this file may not be disclosed to third parties, copied or
#  duplicated in any form, in whole or in part, without the prior written
#  permission of MXCHIP Corporation.
#

NAME := App_WiFi_UART

$(NAME)_SOURCES := MICOAppEntrance.c \
                   MICOBonjour.c \
                   RemoteTcpClient.c \
                   LocalTcpServer.c \
                   SppProtocol.c \
                   UartRecv.c
                   

