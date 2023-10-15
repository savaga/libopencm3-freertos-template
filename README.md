Easy "clone and go" repository for a FreeRTOS & libopencm3 based project.

# Instructions
 1. git clone --recurse-submodules https://github.com/savaga/libopencm3-freertos-template.git your-project
 2. cd your-project
 3. make -C libopencm3 # (Only needed once)
 4. make -C src TARGET=<target> PROJECT=<you-project>

If you got ahead of yourself and skipped the ```--recurse-submodules```
you can fix things by running ```git submodule update --init``` (This is only needed once)

# Targets
Currently there are 3 different targets: blue pill with f103 (BPF1), blue pill with f303 (BPF3)
and black/green pill with F411 (BPF4)

# Drivers
Added usb_cdc driver (see target specific initialization code in the target dir)
and gpio led driver. The led is on when the usb connection is estanlished.

# As a template
You should replace this with your _own_ README if you are using this
as a template.

# Credits
This template is based on libopencm3/libopencm3-template project.
