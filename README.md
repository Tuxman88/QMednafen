QMednafen
=========

Multi-platform interface for Mednafen, writen with Qt Framework.

This is a Qt 5 project, so, to compile it, you need to install all the relevant packages needed to compile a Qt 5 project.

In Windows or GNU/Linux, run this commands.

--- Creating the project ---

Once cloned, run this command on the project folder:

   $ qmake -project

Make sure that QMake is using Qt 5, since various GNU/Linux distros use both 4.8.x and 5.x versions. In such cases, there might be the binaries "qmake" and "qmake-qt5". Use the later to create the project.

Once the command was launched, open and edit the *.pro file created. Add these options:

CONFIG += debug_and_release
QT += widgets

Save and close the file. Now, run this command:

   $ qmake

That will created the needed Makefile files to compile the project.

--- Compiling ---

Run this command in the project folder:

   $ make
   
And wait. The program takes a lot of time to compile. If none error appears, there must be a binary ready to use. In Windows systems, the binary (the EXE file) is located in the "release" folder.

Remember: The program is still incomplete, so, expect some errors and problems.
