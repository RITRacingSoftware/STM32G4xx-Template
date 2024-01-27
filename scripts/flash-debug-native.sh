#!/usr/bin/env bash

set -x

ELF=/vc/build/stm32/vc.elf

openocd -f ./openocd.cfg -c "program ${ELF} verify reset" &
gdb-multiarch -ex "target extended-remote localhost:3333" ${ELF}
