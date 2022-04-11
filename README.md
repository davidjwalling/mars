### mars

<hr>

#### Projects

|link|description|
|-|-|
|01|Library and driver sources; Pointer to implementation (PIMPL); VS 2019 property sheet, solution, projects; CMake scripts|

<hr>

#### git
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

<hr>

#### Build
Windows 10  
x64 Native Tools Command Prompt for Visual Studio 2019
```
C:\repos\mars> cd 01
C:\repos\mars\01> msbuild mars.sln /p:Platform=x64 /p:Configuration=Debug
C:\repos\mars\01> msbuild mars.sln /p:Platform=x64 /p:Configuration=Release
C:\repos\mars\01> msbuild mars.sln /p:Platform=x86 /p:Configuration=Debug
C:\repos\mars\01> msbuild mars.sln /p:Platform=x86 /p:Configuration=Release
```
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
