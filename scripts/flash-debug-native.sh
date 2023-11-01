#!/usr/bin/env bash

set -x

ELF=/ssdb/build/RITRacing-SSDB.out

openocd -f board/st_nucleo_f0.cfg -c "program ${ELF} verify reset" &
gdb-multiarch -ex "target extended-remote localhost:3333" ${ELF}
