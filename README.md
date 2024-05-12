# Building from scratch

Simple instructions to build from scratch:

```
$ west init
$ west update
$ west build  -- -DEXTRA_DTC_OVERLAY_FILE=board.overlay
```

The `west` subcommands for flashing and debugging are not yet tested.
