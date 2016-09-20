/*
 * MIDIUSB_test.ino
 *
 * Created: 4/6/2015 10:47:08 AM
 * Author: gurbrinder grewal
 * Modified by Arduino LLC (2015)
 */ 

#include "MIDIUSB.h"

#define NBSTAIRS 20

// First parameter is the event type (0x09 = note on, 0x08 = note off).
// Second parameter is note-on/note-off, combined with the channel.
// Channel can be anything between 0-15. Typically reported to the user as 1-16.
// Third parameter is the note number (48 = middle C).
// Fourth parameter is the velocity (64 = normal, 127 = fastest).

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

bool pressed[NBSTAIRS];

void setup() {
  Serial.begin(115200);

  for (int i = 1; i<NBSTAIRS; i++) {
    pinMode(i, INPUT_PULLUP);
    pressed[i] = false;
  }
}

// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void loop() {
  for (int i = 1; i < NBSTAIRS; i++) {
    if ((digitalRead(i)==LOW)!=pressed[i]) {
      pressed[i] = !pressed[i];
      if (pressed[i]) {
        Serial.println("Sending note on");
        noteOn(1, 48+i, 100);   // Channel 0, middle C, normal velocity
        MidiUSB.flush();
      } else {
        Serial.println("Sending note off");
        noteOff(1, 48+i, 100);  // Channel 0, middle C, normal velocity
        MidiUSB.flush();
      }
    }
  }
}
