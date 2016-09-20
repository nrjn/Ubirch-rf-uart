# ubirch#1 project template

Example project that just blinks the LED. It depends on the [ubirch toolchain](https://github.com/ubirch/ubirch-meta).
The default code uses the [ubirch#1 r0.2 board](https://github.com/ubirch/ubirch-board-firmware/tree/master/board/ubirch1r02).
If you want to use a different board, add `-DBOARD=...` to the `cmake` command line below.

## Preparation

Have the [ubirch toolchain](https://github.com/ubirch/ubirch-meta) ready:

```
git clone git@github.com:ubirch/ubirch-meta.git
cd ubirch-meta
./build.sh -a
```

## Build example project

Either [download this template](https://github.com/ubirch/ubirch-project-template/archive/master.zip) or
check out using git: `git clone git@github.com:ubirch/ubirch-project-template.git`. Then build using the following commands:
```
cd ubirch-project-template
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=<ubirch-meta-dir>/ubirch-arm-toolchain/cmake/ubirch-arm-gcc-toolchain.cmake
make
make ubirch-template-gdb
```

## Configuration

This template also contains code to create a `config.h` file from a template (`config.h.template`). The
idea is to have an example template that creates the config header which may contain sensitive information.
In our case, we store APN and username/password info in `config.h` which is protected from being committed to
the repository in [.gitignore](.gitignore).

## License

If not otherwise noted in the individual files, the code in this repository is

__Copyright &copy; 2016 [ubirch](http://ubirch.com) GmbH, Author: Matthias L. Jugel__

```
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```

