sleep
=====

sleep is a command-line application that mimics UNIX's sleep: it waits a set amount of time before exiting.
This is useful in some scenarios where your scripts need to wait an arbritary amount of time in between steps.
Now, I realize that GNU coreutils package for Windows already provides a true port of the UNIX sleep utility.
This application was made for people who just wanted this one feature or that can't justify to their IT department
installing a whole suite of applications.

The program is written in C and compiled with MinGW32 to avoid any dependencies on Visual Studio. It's also free, and 
open source.