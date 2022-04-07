### vole

<hr>

#### projects

|link|description|
|-|-|
|01|Library and driver sources; Pointer to implementation (PIMPL); VS 2019 property sheet, solution, projects; CMake scripts|

<hr>

#### git
configure
```
git config --global user.name <user>
git config --global user.email <email>
git config --list
```
localize
```
git clone https://github.com/davidjwalling/vole.git
git remote -v
git branch
```
promote
```
git pull
git status
git diff
git add --all
git commit -m"update"
git push
```

<hr>

#### build
Windows - x64 Native Tools Command Prompt for Visual Studio 2019
```
C:\repos\vole\01> msbuild Vole.sln /p:Platform=x64 /p:Configuration=Debug
```
Linux, macOS
```
$ cd 01
$ rm -rf build
$ mkdir build && cd build
$ cmake ..
$ make
# sudo make install
```
