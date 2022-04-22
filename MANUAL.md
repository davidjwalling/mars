### Mars

<hr>

### Chapter 1
This first chapter introduces an absurdly simple library and driver in C++ with Microsoft Visual Studio 2019 solution, properties and project files. The .editorconfig file defines some basic text formatting rules for .cpp, .h, .txt files versus Makefile files. The .gitignore file helps prevent committing compiled artifacts.  

The public API (api.h, driver.h) exposes the public sample interface class "IDriver". The Pointer-to-Implementation (PIMPL) technique is implemented by declaring a singleton instance of the internal Driver class which is encapsulated in driver.cpp. The implication here, is that Driver is not exposed to even other private classes, which must rely on the public interface class IDriver.
#### Files
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
#### Git
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
 #### Build
Windows 10  
- Open an x64 Native Tools Command Prompt for Visual Studio 2019 window

![](https://github.com/davidjwalling/mars/blob/main/images/x64-Native-Tools-Command-Prompt-for-VS-2019.png?raw=true)

```
C:\repos\mars\01> msbuild mars.sln /p:Platform=x64 /p:Configuration=Debug
C:\repos\mars\01> msbuild mars.sln /p:Platform=x64 /p:Configuration=Release
C:\repos\mars\01> msbuild mars.sln /p:Platform=x86 /p:Configuration=Debug
C:\repos\mars\01> msbuild mars.sln /p:Platform=x86 /p:Configuration=Release
```
