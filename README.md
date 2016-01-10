QMednafen
=========

Multi-platform interface for [Mednafen], written with [Qt Framework].

This is a Qt 5 project, so, to compile it, you need to install all the relevant packages needed to compile a Qt 5 project.

Requirements
============

To build QMednafen, you need some components to be installed and ready to use on your system. These requirements are **mandatory** both for Windows and GNU/Linux.

- Qt Framework >= 5.0 (required modules: QtCore, QtGui, QtWidgets)
- QMake >= 3.0
- GCC >= 4.8
- Mednafen >= 0.9.33.x
   
All the steps described in the next points depends on the previous components.


Project creation
================

> IMPORTANT: The program comes with an already configured project file (a .pro file). Such project file must work with GNU/Linux systems. If you want to customize the project, follow these steps.

Before compiling the program, you need to create a custom project for the program. In the following steps, we are supposing that you have access, by command line, to the next programs:

- qmake (or qmake-qt5)
- make
- g++
   
To create a project on the folder, run the following command as normal user in the program folder:

```sh
qmake -project
```

Or, if you have "qmake-qt5"

```sh
qmake-qt5 -project
```
   
Open the new created file, a .pro file. The file must begin with some lines like these ones:

> TEMPLATE = app

> TARGET = FolderName

> INCLUDEPATH += . \

> ...
   
Replace the **FolderName** value on the file with the string **"qmednafen"**. In GNU/Linux, such value is going to be the binary name of the program. In Windows systems, is more easy to use a binary named "qmednafen.exe". Now, your TARGET value must look like this:

> TARGET = qmednafen
   
Now, add the following options after the TARGET value:

> CONFIG += debug_and_release

> CONFIG += console

> QT += widgets
   
Those values are needed to compile the project. On GNU/Linux systems, you might want to add the next lines (are needed to install the program):

> target.path = /usr/bin/

> icons.path = /usr/share/icons/hicolor/512x512/apps/

> icons.files = resources/img/icon/qmednafen.png

> menus.path = /usr/share/applications/

> menus.files = resources/menus/qmednafen.desktop

> INSTALLS += target

> INSTALLS += icons

> INSTALLS += menus
   
Those lines instructs QMake to install the binary file, the program Icon and the Menu entry. So, now, your file must start looking like this:

> TEMPLATE = app

> TARGET = qmednafen

> CONFIG += debug_and_release

> CONFIG += console

> QT += widgets

> target.path = /usr/bin/

> icons.path = /usr/share/icons/

> icons.files = resources/img/icon/qmednafen.png

> menus.path = /usr/share/applications/

> menus.files = resources/menus/qmednafen.desktop

> INSTALLS += target

> INSTALLS += icons

> INSTALLS += menus

> INCLUDEPATH += . \

> ...
   
After that, save the changes. Now, run this command on the program folder as normal user:

```sh
qmake
```
   
Or, if you have "qmake-qt5"
   
```sh
qmake-qt5
```
   
Two folders and some Makefile files must be generated. You are now ready to compile.


Compiling
=========

To compile the project, just run this command on the program folder once the project file is ready (read previous section) as normal user:

```sh
make
```
   
And wait. The program needs, at least, 3 min. to complete the compilation process. If none error is reported, you are ready to install the program.

Installing
==========

In GNU/Linux systems, you need to run this command as root on the program folder:

```sh
make install
```
   
Or, if you have sudo:

```sh
sudo make install
```
   
In Windows systems, you need to keep the EXE file. The EXE file must be located in the **release** folder. Copy the file to the folder of your preference. Also, for Windows, if you want to be able to uninstall all the development stuff (MingW or Qt Framework, etc), you need to keep some DLL files. From the Qt Framework 5 folder (C:\Qt\Qt5.3.0\5.3\mingw482_32\bin\) you need to keep these files:

- icudt52.dll
- icuin52.dll
- icuuc52.dll
- libgcc_s_dw2-1.dll
- libstdc++-6.dll
- libwinpthread-1.dll
- Qt5Core.dll
- Qt5Gui.dll
- Qt5Widgets.dll
   
And, from the platform folder (C:\Qt\Qt5.3.0\5.3\mingw482_32\plugins\platforms), you need to keep the file:

- qwindows.dll
   
But that file must be in a folder called **platforms**. So, to have a standalone QMednafen binary, you need this folder structure:

>   MyQMednafenFolder\
>   - icudt52.dll
>   - icuin52.dll
>   - icuuc52.dll
>   - libgcc_s_dw2-1.dll
>   - libstdc++-6.dll
>   - libwinpthread-1.dll
>   - Qt5Core.dll
>   - Qt5Gui.dll
>   - Qt5Widgets.dll
>   - qmednafen.exe
>   - platforms\
>      - qwindows.dll
      
And, with that, you are ready to go.

[Mednafen]:https://sourceforge.net/projects/mednafen/
[Qt Framework]:http://qt-project.org/
