PROJECT = template
BUILD_DIR = bin

ifndef TARGET
TARGET=BPF1
$(warning TARGET is not defined. Using default $(TARGET). To specify run: 'make -C src TARGET=<target>')
endif

SHARED_DIR = ../lib
TARGET_DIR = ../target/$(TARGET)
FREERTOS_DIR = ../rtos
FREERTOS_FILES = tasks.c timers.c list.c queue.c croutine.c event_groups.c stream_buffer.c port.c

CFILES = main.c rtos.c 
CFILES += $(FREERTOS_FILES)
#AFILES += api-asm.S

include $(TARGET_DIR)/target.mk

FREERTOS_PORT_DIR = $(FREERTOS_DIR)/portable/GCC/$(FREERTOS_PORT)


VPATH += $(SHARED_DIR) $(FREERTOS_DIR) $(FREERTOS_PORT_DIR) $(TARGET_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR) $(FREERTOS_DIR)/include $(FREERTOS_PORT_DIR) $(TARGET_DIR))
OPENCM3_DIR=../libopencm3
TARGET_DEFS += -DTARGET=$(TARGET) -DDEVICE=$(DEVICE)

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
