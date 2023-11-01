FROM ubuntu:22.04

WORKDIR /ssdb

RUN --mount=type=cache,target=/var/lib/apt/lists \
--mount=type=cache,target=/var/cache/apt \
apt-get update && \
apt-get install -y \
cmake \
gcc-arm-none-eabi \
gdb-multiarch \
openocd

# Setup user
ARG UID=1000
ARG UNAME=ssdb
RUN useradd -mu ${UID} -s /usr/bin/bash ${UNAME}
USER ${UID}
