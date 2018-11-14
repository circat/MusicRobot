#include <MIDI.h>

#include "bitArray.h"


struct CustomBaud : public midi::DefaultSettings{
  
    static const long BaudRate = 115200; // Baud rate for midi
};

MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI,CustomBaud ); // Serial1

const int COIL01 = 2;
const int COIL02 = 3;
const int COIL03 = 4;
const int COIL04 = 5;
const int COIL05 = 6;
const int COIL06 = 7;
const int COIL07 = 8;
const int COIL08 = 9;

const int BUTTONCOUNT = 8;
int BUTTONPINS[] = {46, 44, 42, 40, 38,36,34,32};
bitArray BUTTONSTATES(0, 0, 0, 0, 0, 0, 0, 0);
bitArray LASTSTATES(0, 0, 0, 0, 0, 0, 0, 0);
void setup()
{
    
    pinMode(COIL01, OUTPUT);
    pinMode(COIL02, OUTPUT);
    pinMode(COIL03, OUTPUT);
    pinMode(COIL04, OUTPUT);
    pinMode(COIL05, OUTPUT);
    pinMode(COIL06, OUTPUT);
    pinMode(COIL07, OUTPUT);
    pinMode(COIL08, OUTPUT);
    int i;
    for (i = 0; i < BUTTONCOUNT; i = i + 1) {
      pinMode(BUTTONPINS[i] , INPUT);
    }
    MIDI.begin(10); // DECLARE MIDI ch 10
    MIDI.turnThruOn();
    MIDI.setHandleNoteOn(HandleNoteOn); // CALLBACKZ
    MIDI.setHandleNoteOff(HandleNoteOff);// CALLBACKZ
}
    
void loop()
{
 MIDI.read(); 
 int i;
 for (i = 0; i < BUTTONCOUNT; i = i + 1) {
   handleSwitches(BUTTONPINS [i],i);
 }
}

void handleSwitches(int button,int i){
  int state = digitalRead(button);
  LASTSTATES.writeBit(i, BUTTONSTATES.readBit(i));
  BUTTONSTATES.writeBit(i, state);
  if(LASTSTATES.readBit(i) != state&& state == 1){
   MIDI.sendNoteOn(BUTTONPINS[i], 127, 12); // Note,Value,Channel ( Value 0-127)
  }else if(LASTSTATES.readBit(i) != state && state == 0){
   MIDI.sendNoteOn(BUTTONPINS[i], 127, 12); // Note,Value,Channel ( Value 0-127)
  }
}
void HandleNoteOn (byte channel, byte number, byte velocity) { // ON MIDI NOTE ON DO



  if (number == 24) { // BASSDRUM1
  analogWrite(COIL01, 255);
  }
  
  if (number == 25) { // SNAREDRUM
  analogWrite(COIL02, 255);
  }
  
  if (number == 26) { // CLOSEDHIHAT
  analogWrite(COIL03, 255);   
  }
  if (number == 27) { // HANDCLAP/HIGHBONGO
  analogWrite(COIL04, 255);
        
  }
  
  if (number == 28) { // COWBELL / METALL
  analogWrite(COIL05, 255);
 
      
  }
  if (number == 29) { // SNARE2/Metall
  analogWrite(COIL06, 255);
  
      
  }
  if (number == 30) { // TOM1
  analogWrite(COIL07, 255);
     
  }
  
if (number == 31) { //Crash/SERVO1
  
    analogWrite(COIL08, 255);            
     
  }  
   
  
}   
  
void HandleNoteOff(byte channel, byte number, byte velocity) { 

  if (number == 24) { // BASSDRUM1
  
      analogWrite(COIL01,0);
     
  }
  
  if (number == 25) { // SNAREDRUM
  analogWrite(COIL02, 0);
 
  }
  
  if (number == 26) { // CLOSEDHIHAT
  analogWrite(COIL03,0);

  }
  if (number == 27) { // HANDCLAP/HIGHBONGO
 analogWrite(COIL04,0);

  }
  
  if (number == 28) { // COWBELL / METALL
  analogWrite(COIL05, 0);
  
  }
  if (number == 29) { // SNARE2/Metall
  analogWrite(COIL06, 0);
 
  }
  if (number == 30) { // TOM1
  analogWrite(COIL07, 0);
 
  }
  
    
   if (number == 31) { //Crash/SERVO1
  analogWrite(COIL08, 0);
  
  } 
  
}
