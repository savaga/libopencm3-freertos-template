Easy "clone and go" repository for a FreeRTOS & libopencm3 based project.

# Instructions
 1. git clone --recurse-submodules https://github.com/savaga/libopencm3-freertos-template.git your-project
 2. cd your-project
 3. make -C libopencm3 # (Only needed once)
 4. make -C my-project TARGET=<target>

If you got ahead of yourself and skipped the ```--recurse-submodules```
you can fix things by running ```git submodule update --init``` (This is only needed once)

# As a template
You should replace this with your _own_ README if you are using this
as a template.

# Credits
This template is based on libopencm3/libopencm3-template project.
