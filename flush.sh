##!/bin/bash

PROJECT_PATH="$HOME/git/software/qmk_firmware/"

BUILD_NAME="splitkb_aurora_corne_rev1_pyinto_homerow_debug_liatris"

KEYBOARD_MOUNT_PATH="/Volumes/RPI-RP2/"


cp $PROJECT_PATH/.build/$BUILD_NAME.uf2 $KEYBOARD_MOUNT_PATH
