#include <libopencm3/usb/usbd.h>
#include "cdc.h"

const void *usb_driver = &st_usbfs_v1_usb_driver;

void usb_init_hook(void) {

}

