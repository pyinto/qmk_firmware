# Aurora Corne's Debug Keymap

To make debugging your build as easy as possible, we have provided a special debugging keymap. It is not intended to actually type on, it is just here to make sure that your hardware is working correctly.

## Keys

![Keys](https://i.imgur.com/y5zWjsZh.png)

The left side uses lowercase letters, the right side uses uppercase ones.

## Encoders

Encoders output a number of 0 or 1, depending on the installed position.
These correspond to the index used for custom encoder code.

The number is followed by either a `+` or a `-`, depending on the direction turned.

## LEDs

Both underglow and per-key RGB should be fading between red and off.

## OLEDs

Both the primary and secondary side should be filled with characters.



## Building & Flashing
https://docs.splitkb.com/hc/en-us/articles/6330981035676-Aurora-Build-Guide-20-Flashing-Firmware

```
qmk compile -kb splitkb/aurora/corne/rev1 -km pyinto_homerow_debug
qmk compile -kb splitkb/aurora/corne/rev1 -km pyinto_homerow_debug -e CONVERT_TO=liatris
qmk compile -kb splitkb/aurora/corne/rev1 -km x123

// doesn't work:
qmk compile -kb splitkb/aurora/corne -km pyinto_homerow_debug -e CONVERT_TO=liatris
[//]: # (qmk flash -c -kb splitkb/aurora/corne -km debug -e CONVERT_TO=liatris)

qmk compile -kb splitkb/aurora/corne -km default -e CONVERT_TO=liatris



```
