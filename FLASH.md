Board:
https://github.com/qmk/qmk_firmware/tree/master/keyboards/evyd13/plain60

Steps:

* install qmk pkg -- https://docs.qmk.fm/newbs_getting_started
* copy qmk_firmware repo 
  * changed repo `git clone git@github.com:ecks/qmk_firmware.git` and `git checkout hsa`
  * clean unchanged repo `git clone git@github.com:qmk/qmk_firmware.git`
* change file in qmk_firmware/beyboards/evyd13/plain60/keymaps/default/keymap.c
* qmk compile -kb evyd13/plain60 -km default
* Set keyboard in Bootloader mode: https://docs.qmk.fm/newbs_flashing. There is also a button on the back you can press
* qmk flash -kb evyd13/plain60 -km default

Useful for testing: https://config.qmk.fm/#/test
