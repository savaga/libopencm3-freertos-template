#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/dwc/otg_fs.h>

#include "cdc.h"

const void *usb_driver = &otgfs_usb_driver;

void usb_init_hook(void) {
    OTG_FS_GCCFG |= OTG_GCCFG_NOVBUSSENS | OTG_GCCFG_PWRDWN;
    OTG_FS_GCCFG &= ~(OTG_GCCFG_VBUSBSEN | OTG_GCCFG_VBUSASEN);
}

