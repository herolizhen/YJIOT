#
#  UNPUBLISHED PROPRIETARY SOURCE CODE
#  Copyright (c) 2016 MXCHIP Inc.
#
#  The contents of this file may not be disclosed to third parties, copied or
#  duplicated in any form, in whole or in part, without the prior written
#  permission of MXCHIP Corporation.
#


NAME := App_mqtt_client


$(NAME)_SOURCES := mqtt_client.c
# mqtt_task.c
				   
				  
$(NAME)_COMPONENTS := protocols/mqtt
