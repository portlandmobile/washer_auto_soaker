# This is the project that allows the push button to create the washer cycle with soaking function. 

## Project Hardware
**ESP32 S3 DevKitC-1-N8R2** The project use this hardware board.  The spec and manual is here. https://drive.google.com/file/d/1NSoKTQjtP6hYtOB2olofZcJVkgJ6W-0s/view?usp=drive_link

**3D Casing** The casing is built using the following design in TinkerCad (SSO with Google luv2whitewater)
 -- Push Arm : https://www.tinkercad.com/things/cvzryA5OQ2V-copy-of-copy-of-washer-arm-from-bamboo-store/edit?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2F3d
 -- Casing for the board and the touch sensor: 
     * https://www.tinkercad.com/things/fSeEBKMLMeW-sg90-and-ttp223-enclosures/edit?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2F3d
     * https://www.tinkercad.com/things/jqYGl4VKIWe-cool-blad-densor/edit?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2F3d

**Software** 
-- Use VS Code IDE to build
-- PlatformIO (aka PIO) Integration with VS Code for the ESP32 library
-- Git repo here: https://github.com/portlandmobile/washer_auto_soaker


**Download**
-- Connect the USB C from Macbook to the left port on the board. (the right port is serial port)
-- First build the project by pressing the "check" button at the lower left corner.
-- Then press the "right arrow" to upload the firmware to the board after pressing the Boot push button on the board