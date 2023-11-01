environment:
- gitattributes:
  - LF vs CRLF, see [VS Code remote debug troubleshooting](https://code.visualstudio.com/docs/remote/troubleshooting#_resolving-git-line-ending-issues-in-wsl-resulting-in-many-modified-files)
- gitignore
- README
  - Project intro
  - Needed software: docker, git
  - Recommended software: VS Code
  - Native compile: arm cross-compiler, cmake, python3?, meson?
- vs code configs

build:
- submodules:
  - DBC, either compiled or raw
  - freertos
- dockerfile
- helper scripts - sh and cmd
- cmakelists

code:
- linker script
- stm32 drivers
- hello world code
- unit tests - googletest+googlemock?
