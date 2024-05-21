# Building from scratch

Simple instructions to build from scratch:

```
$ west init
$ west update
$ west build  -- \
  -DEXTRA_DTC_OVERLAY_FILE=board.overlay \
  -DOPENOCD=/usr/local/bin/openocd \
  -DOPENOCD_DEFAULT_PATH=/usr/local/share/openocd/scripts \
  -DRPI_PICO_DEBUG_ADAPTER=cmsis-dap
$ west flash
```

The `west` subcommands debugging are not yet tested.

