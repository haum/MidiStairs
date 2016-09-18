PianoStairs
===========

This repository aims to provide sufficient element to create a PianoStairs.

Our PianoStairs is made with two electronic parts : MidiStairs and a RpiMidiSynth.

Hardware requirements
---------------------

 * Arduino Leonardo
 * Raspberry Pi

Part 1 : MidiStairs
-------------------

This part, made around an Arduino Leonardo, will turn some button presses in MIDI messages via USB.

Part 2 : RpiMidiSynth
---------------------

This is made using a Raspberry Pi which will convert MIDI messages into audio.

```
apt install git alsa-utils fluidsynth fluid-soundfont-gm
git clone git@github.com:haum/PianoStairs.git
cd PianoStairs/rpimidisynth
make install
sudo reboot
```

