##!/bin/bash

MY_KEYBOARD="splitkb/aurora/corne"

MY_KEYMAP="pyinto_homerow_debug"

qmk compile -kb $MY_KEYBOARD -km $MY_KEYMAP
