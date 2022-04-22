## Mars

<hr>

## Chapter 1
This first chapter introduces an absurdly simple library and driver in C++ with Microsoft Visual Studio 2019 solution, properties and project files. The .editorconfig file defines some basic text formatting rules for .cpp, .h, .txt files versus Makefile files. The .gitignore file helps prevent committing compiled artifacts.  

The public API (api.h, driver.h) exposes the public sample interface class "IDriver". The Pointer-to-Implementation (PIMPL) technique is implemented by declaring a singleton instance of the internal Driver class which is encapsulated in driver.cpp. The implication here, is that Driver is not exposed to even other private classes, which must rely on the public interface class IDriver.
### Files
```
01 ---+--- libmars ------- api.h
      |               +--- driver.dpp
      |               +--- driver.h
      |               +--- libmars.vcxproj
      |               +--- libmars.vcxproj.filters
      +--- mars ---------- main.cpp
      |               +--- mars.vcxproj
      |               +--- mars.vcxproj.filters
      +--- mars.pros
      +--- mars.sln
.editorconfig
.gitignore
LICENSE
MANUAL.md
README.md
```
### Git
Configure
```
git config --global user.name <user>
git config --global user.email <email>
git config --list
```
Localize
```
git clone https://github.com/davidjwalling/mars.git
git remote -v
git branch
```
Promote
```
git pull
git status
git diff
git add --all
git commit -m"update"
git push
```
### Build
#### Windows 10 with msbuild
- Open an x64 Native Tools Command Prompt for Visual Studio 2019 window

![x64 Native Tools](https://github.com/davidjwalling/mars/blob/main/images/x64-Native-Tools-Command-Prompt-for-VS-2019.png?raw=true)

```
C:\repos\mars\01> msbuild mars.sln /p:Platform=x64 /p:Configuration=Debug
C:\repos\mars\01> msbuild mars.sln /p:Platform=x64 /p:Configuration=Release
C:\repos\mars\01> msbuild mars.sln /p:Platform=x86 /p:Configuration=Debug
C:\repos\mars\01> msbuild mars.sln /p:Platform=x86 /p:Configuration=Release
```
<hr>

## Chapter 2
This chapter adds CMake files for the library and driver and for the top-level project. With CMake, we can build the project with several different generators. We'll show examples using "Ninja", "NMake Makefiles" and "Visual Studio 16 2019" generators.  

For Windows builds, When building within a Visual Studio environment, such as x64 Native Tools, CMake and Ninja are provided. Be aware of the versions shipped with the compiler. When building from a standard command prompt, a separately-installed version of CMake might run, depending on your PATH settings.

For Linux and macOS builds, CMake will identify the GCC or CLang compiler as usual.
### Files
```
02 ---+--- libmars ------- CMakeLists.txt              <--- new
      |               +--- api.h
      |               +--- driver.dpp
      |               +--- driver.h
      |               +--- libmars.vcxproj
      |               +--- libmars.vcxproj.filters
      +--- mars ---------- CMakeLists.txt              <--- new
      |               +--- main.cpp
      |               +--- mars.vcxproj
      |               +--- mars.vcxproj.filters
      +--- CMakeLists.txt                              <--- new
      +--- mars.pros
      +--- mars.sln
.editorconfig
.gitignore
LICENSE
MANUAL.md
README.md
```
### Build
#### Windows 10 with CMake -G "Visual Studio 16 2019"
- Install CMake (kitware.com/cmake)
- Add "C:\Program Files (x86)\MARS\bin" to your system path
- Open a standard Command Prompt as Administrator

![Command Prompt as Admin](https://github.com/davidjwalling/mars/blob/main/images/Command-Prompt-as-Administrator.png?raw=true)

```
C:\repos\mars\02> where cmake
C:\Program Files\CMake\bin\cmake.exe
C:\repos\mars\02> cmake --version
cmake version 3.23.0-rc2
C:\repos\mars\02> rmdir /s /q build
C:\repos\mars\02> mkdir build && cd build
C:\repos\mars\02\build> cmake -G "Visual Studio 16 2019" -A x64 ..
-- Selecting Windows SDK version 10.0.19041.0 to target Windows 10.0.19043.
-- The C compiler identification is MSVC 19.29.30141.0
-- The CXX compiler identification is MSVC 19.29.30141.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: C:/repos/mars/02/build

C:\repos\mars\02\build> cmake --build . --config Debug --target install
Microsoft (R) Build Engine version 16.11.2+f32259642 for .NET Framework
Copyright (C) Microsoft Corporation. All rights reserved.

  Checking Build System
  Building Custom Rule C:/repos/mars/02/libmars/CMakeLists.txt
  driver.cpp
     Creating library C:/repos/mars/02/build/libmars/Debug/libmars.lib and object C:/repos/mars/02/build/libmars/Debug/libmars.exp
  libmars.vcxproj -> C:\repos\mars\02\build\libmars\Debug\libmars.dll
  Building Custom Rule C:/repos/mars/02/mars/CMakeLists.txt
  main.cpp
  mars.vcxproj -> C:\repos\mars\02\build\mars\Debug\mars.exe
  Building Custom Rule C:/repos/mars/02/CMakeLists.txt
  -- Install configuration: "Debug"
  -- Installing: C:/Program Files/MARS/lib/libmars.lib
  -- Installing: C:/Program Files/MARS/bin/libmars.dll
  -- Installing: C:/Program Files/MARS/include/api.h
  -- Installing: C:/Program Files/MARS/include/driver.h
  -- Old export file "/cmake/mars/MarsConfig.cmake" will be replaced.  Removing files [/cmake/mars/MarsConfig-debug.cmake;/cmake/mars/MarsConfig-release.cmake].
  -- Installing: /cmake/mars/MarsConfig.cmake
  -- Installing: /cmake/mars/MarsConfig-debug.cmake
  -- Installing: C:/Program Files/MARS/bin/libmars.pdb
  -- Installing: C:/Program Files/MARS/bin/mars.exe

C:\repos\mars\02\build> mars
Hello, Driver!
```
#### Windows 10 with CMake -G "NMake Makefiles"
- Add "C:\Program Files (x86)\MARS\bin" to your system path
- Open an x64 Native Tools Command Prompt for Visual Studio 2019 window _as Administrator_

![x64 Native Tools as Admin](https://github.com/davidjwalling/mars/blob/main/images/x64-Native-Tools-Command-Prompt-for-VS-2019-as-Administrator.png?raw=true)

```
C:\repos\mars\02> rmdir /s /q build
C:\repos\mars\02> mkdir build && cd build
C:\repos\mars\02\build> cmake -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
-- The C compiler identification is MSVC 19.29.30141.0
-- The CXX compiler identification is MSVC 19.29.30141.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: C:/repos/mars/02/build
```

![NMake Install](https://github.com/davidjwalling/mars/blob/main/images/NMake-Install.png?raw=true)
#### Windows 10 with CMake -G "Ninja"
- Add "C:\Program Files (x86)\MARS\bin" to your system path
- Open an x64 Native Tools Command Prompt for Visual Studio 2019 window _as Administrator_

![x64 Native Tools as Admin](https://github.com/davidjwalling/mars/blob/main/images/x64-Native-Tools-Command-Prompt-for-VS-2019-as-Administrator.png?raw=true)

```
C:\repos\mars\02> rmdir /s /q build
C:\repos\mars\02> mkdir build && cd build
C:\repos\mars\02\build> cmake -G "Ninja"  ..
-- The C compiler identification is MSVC 19.29.30141.0
-- The CXX compiler identification is MSVC 19.29.30141.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: C:/repos/mars/02/build

C:\repos\mars\02\build>cmake --build . --config Debug --target install
[4/5] Install the project...
-- Install configuration: "Debug"
-- Installing: C:/Program Files (x86)/MARS/lib/libmars.lib
-- Installing: C:/Program Files (x86)/MARS/bin/libmars.dll
-- Up-to-date: C:/Program Files (x86)/MARS/include/api.h
-- Up-to-date: C:/Program Files (x86)/MARS/include/driver.h
-- Installing: /cmake/mars/MarsConfig.cmake
-- Installing: /cmake/mars/MarsConfig-debug.cmake
-- Installing: C:/Program Files (x86)/MARS/bin/libmars.pdb
-- Installing: C:/Program Files (x86)/MARS/bin/mars.exe

C:\repos\mars\02\build>mars
Hello, Driver!
```
#### Ubuntu Linux 20.04
```
osboxes@osboxes:~/repos/mars/02$ mkdir build && cd build
osboxes@osboxes:~/repos/mars/02/build$ cmake ..
-- The C compiler identification is GNU 9.4.0
-- The CXX compiler identification is GNU 9.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/osboxes/repos/mars/02/build
```

![osboxes cmake](https://github.com/davidjwalling/mars/blob/main/images/osboxes-cmake.png?raw=true)

#### macOS Big Sur version 11.6.5
```
me@Mes-MacBook-Pro 02 % mkdir build && cd build
me@Mes-MacBook-Pro build % cmake ..
-- The C compiler identification is AppleClang 13.0.0.13000029
-- The CXX compiler identification is AppleClang 13.0.0.13000029
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/me/repos/mars/02/build
```

![macos cmake](https://github.com/davidjwalling/mars/blob/main/images/macos-cmake.png?raw=true)
