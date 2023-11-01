#!/usr/bin/env bash

docker run -it \
	--mount type=bind,source=$PWD,destination=/ssdb \
	--privileged \
	ssdb \
	scripts/flash-debug-native.sh
