#!/usr/bin/env bash

git submodule update --init --recursive
docker build --build-arg=UID=$(id -u) --build-arg=UNAME=$(id -nu) ./docker/ -t temp
