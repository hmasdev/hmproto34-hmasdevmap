# hmproto34-hmasdevmap

`hmproto34-hmasdevmap` provides a keymap for [hmproto34](https://github.com/hmasdev/hmproto34) and [hmproto34s](https://github.com/hmasdev/hmproto34s) keyboards.

## How to Use

The simplest way to use this keymap is to flash the pre-built firmware.
You can find the latest firmware in the [releases](https://github.com/hmasdev/hmproto34-hmasdevmap/releases) section of this repository.
Download the firmware file and flash it to your keyboard using the appropriate method for your keyboard, like [Pro Micro Web Updater](https://sekigon-gonnoc.github.io/promicro-web-updater/index.html).

### How to Build

In this section, we will go through the steps to build the firmware from source.

1. Set up your QMK environment if you haven't already. Follow the instructions in the [QMK documentation](https://docs.qmk.fm/#/newbs_getting_started) to set up your QMK environment.

2. Clone the repository:

   ```bash
   cd ~/qmk_firmware/keyboards
   git clone https://github.com/hmasdev/hmproto34 # or git clone https://github.com/hmasdev/hmproto34s
   git clone https://github.com/hmasdev/hmproto34-hmasdevmap
   cp -r hmproto34-hmasdevmap/keyboards/hmproto34/keymaps/hmasdevmap hmproto34/keymaps/hmasdevmap
   ```

3. Build the firmware:

   ```bash
   qmk compile -kb hmproto34 -km hmasdevmap
   ```
