
//   3: Analog DAC - Connect the DAC pin to an amplified speaker
//         http://www.pjrc.com/teensy/gui/?info=AudioOutputAnalog

#include <Audio.h>
//#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <MIDI.h>

AudioPlaySdWav           playWav1;
// Use one of these 3 output types: Digital I2S, Digital S/PDIF, or Analog DAC
//AudioOutputI2S           audioOutput;
//AudioOutputSPDIF       audioOutput;
AudioOutputAnalog      audioOutput;
AudioConnection          patchCord1(playWav1, 0, audioOutput, 0);
AudioConnection          patchCord2(playWav1, 1, audioOutput, 1);
AudioControlSGTL5000     sgtl5000_1;

// Use these for the SD+Wiz820 or other adaptors
#define SDCARD_CS_PIN    4
#define SDCARD_MOSI_PIN  11
#define SDCARD_SCK_PIN   13
struct CustomBaud : public midi::DefaultSettings{
    //static const long BaudRate = 31250; // Baud rate for midi
    static const long BaudRate = 115200; // Baud rate for midi
};

MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial1, MIDI,CustomBaud ); // Serial1


void setup() {
  //Serial.begin(9600);

  // Audio connections require memory to work.
  AudioMemory(8);

  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    // stop here, but print a message repetitively
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
  MIDI.begin(11); // DECLARE MIDI ch 10
    //Serial.begin(115200);
    //MIDI.turnThruOff();
     MIDI.turnThruOn();
    MIDI.setHandleNoteOn(HandleNoteOn); // CALLBACKZ
    MIDI.setHandleNoteOff(HandleNoteOff);// CALLBACKZ
}

void playFile(const char *filename)
{
  Serial.print("Playing file: ");
  Serial.println(filename);

  // Start playing the file.  This sketch continues to
  // run while the file plays.
  playWav1.play(filename);

  // A brief delay for the library read WAV info
  delay(5);

  // Simply wait for the file to finish playing.
  while (playWav1.isPlaying()) {
    // uncomment these lines if you audio shield
    // has the optional volume pot soldered
    //float vol = analogRead(15);
    //vol = vol / 1024;
    // sgtl5000_1.volume(vol);
  }
}


void loop() {
  MIDI.read();
  //playFile("REF1.WAV");  // filenames are always uppercase 8.3 format
  //playFile("SL.WAV");  // filenames are always uppercase 8.3 format
  //delay(500);
 //playFile("REF1.raw");  // filenames are always uppercase 8.3 format
 // delay(500);
}
void HandleNoteOn (byte channel, byte number, byte velocity) { // ON MIDI NOTE ON DO

//strenth = map(velocity, 0, 127, 30, 255); //35, seems to be the right value for putting all the coils on at velocity 127

//int notelength = 50;

  if (number == 36) { // BASSDRUM1
  playWav1.play("REF1.WAV");
  Serial.println("MIDI");
      
  }}

  void HandleNoteOff(byte channel, byte number, byte velocity) { 

  if (number == 36) { // BASSDRUM1
  //analogWrite(COIL[0], LOW);
  playWav1.stop();
  //fill_solid(leds, NUM_LEDS, CRGB::Black); // Set all to red.
     // FastLED.show();   
  }}
