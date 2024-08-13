#!/usr/bin/env bash

set -x

ELF=build/stm32/temp-f32.elf

openocd -f ./openocd.cfg -c "program ${ELF} verify reset" -c "exit"