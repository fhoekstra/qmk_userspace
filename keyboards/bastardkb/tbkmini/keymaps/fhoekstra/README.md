My TBKMini has the older Elite-C controller so it may not fit very complex keymaps and RGB effects, especially on newer versions of QMK as the basic firmware keeps getting bigger.

This is my QMK config while I'm daily driving this board:

```text
find.keymap=default
mass_compile.keymap=default
user.keyboard=bastardkb/tbkmini/v1/elitec
user.keymap=fhoekstra
user.overlay_dir=/home/freek/Source/qmk_userspace
user.qmk_home=/home/freek/Source/qmk_firmware
# qmk_firmware version 0.29.12 is used
```
