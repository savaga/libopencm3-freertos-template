
$(info Compiling target: BPF1: Bluepill with F1 mcu)

DEVICE=stm32f103t8t6
OOCD_INTERFACE = stlink-v2
OOCD_TARGET = stm32f1x
FREERTOS_PORT = ARM_CM3

TARGET_DEFS =

CFILES += target.c usb.c
