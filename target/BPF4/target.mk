$(info Compiling target: BPF4: Bluepill with F4 mcu)

DEVICE=stm32f411ceu6
OOCD_INTERFACE = stlink-v2
OOCD_TARGET = stm32f4x
FREERTOS_PORT = ARM_CM4F

TARGET_DEFS =

CFILES += target.c
