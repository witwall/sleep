sleep
=====

**About sleep**
```
The sleep command is used to delay for a specified amount of time.
```
**Syntax**
```
sleep.exe NUMBER[SUFFIX] ...
```
```
sleep.exe [OPTION]
```

**Description**

The sleep command pauses for an amount of time defined by NUMBER.

SUFFIX may be "s" for seconds, "m" for minutes, "h" for hours, or "d" for days. 

if no suffix, means milliseconds.

If more than one NUMBER is specified, sleep delays for the sum of their values.

**Options**


|--help|Display a help message, and exit.|
|---|---|
|--version|Display version information, and exit.|

**Examples**

```
sleep 10
```

Delays for 10 milliseconds.

**Remark**

The program is written in C and compiled with MinGW32 to avoid any dependencies on Visual Studio. It's also free, and 
open source.

