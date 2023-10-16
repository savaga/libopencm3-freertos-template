PROJECT ?= template
FREERTOS_DYNAMIC_MEMMANG ?= 0
FREERTOS_MEMMANG ?= heap_4.c

ifndef TARGET
TARGET=BPF1
$(warning TARGET is not defined. Using default $(TARGET). To specify run: 'make -C src TARGET=<target>')
endif

BUILD_DIR = bin/$(TARGET)

DRIVER_DIR = ../driver
SHARED_DIR = ../lib
TARGET_DIR = ../target/$(TARGET)
FREERTOS_DIR = ../rtos
FREERTOS_FILES = tasks.c timers.c list.c queue.c croutine.c event_groups.c stream_buffer.c port.c

LWRB_DIR = $(SHARED_DIR)/lwrb/lwrb/src
LWRB_INC = $(LWRB_DIR)/include
LWRB_SRC = $(LWRB_DIR)/lwrb

CFILES = main.c rtos.c cdc.c lwrb.c
CFILES += $(FREERTOS_FILES)
#AFILES += api-asm.S

include $(TARGET_DIR)/target.mk

FREERTOS_PORT_DIR = $(FREERTOS_DIR)/portable/GCC/$(FREERTOS_PORT)

ifeq ($(FREERTOS_DYNAMIC_MEMMANG), 1)
FREERTOS_FILES += $(FREERTOS_MEMMANG)
FREERTOS_MEMMANG_DIR = $(FREERTOS_DIR)/portable/MemMang
TARGET_DEFS += -DFREERTOS_DYNAMIC_MEMMANG
else
FREERTOS_MEMMANG_DIR =
endif

VPATH += $(SHARED_DIR) $(FREERTOS_DIR) $(FREERTOS_PORT_DIR) $(TARGET_DIR) $(FREERTOS_MEMMANG_DIR) $(DRIVER_DIR) $(LWRB_SRC)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR) $(FREERTOS_DIR)/include $(FREERTOS_PORT_DIR) $(TARGET_DIR) $(DRIVER_DIR)/include $(LWRB_INC))
OPENCM3_DIR=../libopencm3
TARGET_DEFS += -DTARGET=$(TARGET) -DDEVICE=$(DEVICE)

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
