$(info Compiling target: BPF3: Bluepill with F3 mcu)

DEVICE=stm32f303cct6
OOCD_INTERFACE = stlink-v2
OOCD_TARGET = stm32f3x
FREERTOS_PORT = ARM_CM4F

TARGET_DEFS =

CFILES += target.c
