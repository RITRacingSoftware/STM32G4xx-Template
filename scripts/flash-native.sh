#!/usr/bin/env bash

set -x

ELF=build/ssdb.elf

openocd -f ./openocd.cfg -c "program ${ELF} verify reset"
