# Particle-based Roomba "Virtual Wall"

This firmware enables a Photon to control a set of infrared LEDs and emulate a set of Roomba "virtual walls".

## Construction

Positive leads for all LEDs should be attached to pins D0 through D3, with the negative leads for each LED attached to the GND pin. _Don't forget to put resistors inline with the LEDs._ You probably want 180Ω resistors.

## Building the firmware

The firmware can be built using the `particle` CLI, substituting your own Photon's device ID or name for $DEVICE_ID. From the root directory of this repo:

```
particle flash $DEVICE_ID
```

## Particle Cloud API

This firmware uses the Particle Cloud API, exposing the following (requires the device's ID, which can be found with `particle list`):

`POST /v1/devices/{DEVICE_ID}/enable` - Takes one argument, the pin to enable, as `args=0`. If an invalid string is provided, pin D0 will be enabled.
`POST /v1/devices/{DEVICE_ID}/disable` - Takes one argument, the pin to disable, as `args=0`. If an invalid string is provided, pin D0 will be disabled.
