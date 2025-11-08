# Cheapino

The Cheapino does not currently support a qmk *userspace* setup.
To use my Cheapino keymap, follow the instructions on [the tompi/cheapino firmware guide](https://github.com/tompi/cheapino/blob/master/doc/firmware.md#setting-up-and-compiling-qmk) and copy these files over to your qmk *firmware* directory.

> [!NOTE]
> The ./encoder.c file here lives in the cheapino root, but is tightly coupled to the layers, so it only fully works with a specific keymap. Look at it and change as needed to fit your keymap.
