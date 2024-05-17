# Building from scratch

Simple instructions to build from scratch:

```
$ west init
$ west update
$ west build  -- -DEXTRA_DTC_OVERLAY_FILE=board.overlay
```

For now `west` is not able to flash the generated image. To flash the built image, run the command:

```
$ sudo openocd \
    -f /opt/pico/openocd/tcl/interface/cmsis-dap.cfg \
    -f /opt/pico/openocd/tcl/target/rp2040.cfg \
    -c "adapter speed 5000" \
    -c "program build/zephyr/zephyr.elf verify reset exit"
```

The `west` subcommands debugging are not yet tested.

