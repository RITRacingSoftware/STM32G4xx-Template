docker run -it ^
	--mount type=bind,source=%cd%,destination=/ssdb ^
	ssdb ^
	scripts/build-native.sh
