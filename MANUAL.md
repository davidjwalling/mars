### Mars
Technical Manual  
22 April 2022  
<hr>

### Chapter 1
#### Files
```
01 ------- libmars ------- api.h
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
**********************************************************************
** Visual Studio 2019 Developer Command Prompt v16.11.11
** Copyright (c) 2021 Microsoft Corporation
**********************************************************************
[vcvarsall.bat] Environment initialized for: 'x64'

C:\Program Files (x86)\Microsoft Visual Studio\2019\Community>cd \repos\mars\01
C:\repos\mars\01> msbuild mars.sln /p:Platform=x64 /p:Configuration=Debug
C:\repos\mars\01> msbuild mars.sln /p:Platform=x64 /p:Configuration=Release
C:\repos\mars\01> msbuild mars.sln /p:Platform=x86 /p:Configuration=Debug
C:\repos\mars\01> msbuild mars.sln /p:Platform=x86 /p:Configuration=Release
```