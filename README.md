# open source embedded controller firmware for H8/S 2161 [built-in Thinkpad T40]

## how to compile
Because of time pressure I'm still using the debian package gcc-h8300-hms/binutils-h8300-hms
On debian jessy
- gcc-h8300-hms
- binutils-h8300-hms
- build-essentials

Just do make

## how to flash the firmware to a device?
At the moment the only possible way to flash this firmware is using the ROM loader.
To access the ROM loader you must change solder several pins to enter it.
Pins: P90, P91, P92, mode0, mode1

After you have activated the boot loader mode, you can use the official renesas
flash kit. It's possible to use open source flash software, but this wasn't done
because of time pressure.

Use blinkled.mot with reneases flash tool kit
