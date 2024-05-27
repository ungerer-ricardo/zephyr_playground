## VSCode Integration

There are VSCode configurations that enable the developer to call vscode tasks to:

- build
- flash
- debug

## Building from scratch

Simple instructions to build from scratch:

```
$ rm -rf .west tools modules bootloader zephyr
$ west init
$ west update
$ west build  --board rpi_pico/rp2040/w -- \
  -DEXTRA_DTC_OVERLAY_FILE=board.overlay \
  -DOPENOCD=/usr/local/bin/openocd \
  -DOPENOCD_DEFAULT_PATH=/usr/local/share/openocd/scripts \
  -DRPI_PICO_DEBUG_ADAPTER=cmsis-dap
```
### Flashing

To flash the RaspberryPi pico using a terminal:

```
$ west flash
```

### Debugging

To start a debug session:

```
$ west debug
```

## Known Issues

### DevContainer

- When debuggin in terminal, it is not Possible to set breakpoint using `b main`.
  Other functions works well though
