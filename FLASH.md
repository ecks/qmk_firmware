Board:
https://github.com/qmk/qmk_firmware/tree/master/keyboards/evyd13/plain60

Steps:

install qmk pkg -- https://docs.qmk.fm/newbs_getting_started
copy repo https://github.com/qmk/qmk_firmware

change file in qmk_firmware/beyboards/evyd13/plain60/keymaps/default/keymap.c
qmk compile -kb evyd13/plain60 -km default
Set keyboard in Bootloader mode: https://docs.qmk.fm/newbs_flashing
qmk flash -kb evyd13/plain60 -km default

Useful for testing: https://config.qmk.fm/#/test
