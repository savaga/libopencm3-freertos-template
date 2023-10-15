#ifndef __CDC_H__
#define __CDC_H__

extern const void *usb_driver;

void usb_init_hook(void);
void cdcacm_init(void);
void cdcacm_poll(void);
bool cdcacm_is_connected(void);

#endif /* __CDC_H__ */
