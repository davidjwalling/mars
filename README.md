### mars

<hr>

#### Projects

|link|description|
|-|-|
|01|Library and driver C++ sources; Pointer to implementation (PIMPL); VS 2019 property sheet, solution, projects.|
|02|Add CMake scripts for Windows builds using Ninja, NMake and Visual Studio generators. Build on Linux and macOS.|

<hr>

![RTFM](MANUAL.md)

<hr>

#### Build
Linux
```
$ cd 01
$ rm -rf build
$ mkdir build && cd build
$ cmake ..
$ make
$ sudo make install
$ sudo ldconfig
```
macOS
```
$ cd 01
$ rm -rf build
$ mkdir build && cd build
$ cmake ..
$ make
$ sudo make install
```
